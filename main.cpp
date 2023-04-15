#include "Board_Evolution/evolve.hpp"
#include "Board_Evolution/step.hpp"
#include "Board_Utilities/board.hpp"
#include "Input_Config/input.hpp"
#include <chrono>
#include <thread>

int main() {

  // READING the input configurations
  std::ifstream is{"Input_Config/SETTINGS.txt"};

  // Creating default input file if this is not present
  if (!is) {
    default_input_file();
  }

  std::cout
      << "\u001b[33;1m"
      << "\n(!)"
      << "\u001b[37;1m"
      << " Welcome to the epidemic simulator. \nThis program allows you to "
         "simulate an epidemic evolution in a population.\nTo start go to "
         "Input_Config/SETTINGS.txt and insert you personal settings. "
         "\nOtherwise you can do nothing and run the program with the default "
         "input configurations.\nWhen you are ready press Enter to continue.\n";

  std::string line;
  std::getline(std::cin, line);

  // Check if the input files are correct and readable
  check_input_file();
  // Creating the input values
  Input_Values values = read_input();

  Board board{values.base, values.height};
  Step step{values.quarantine_threshold};
  Evolve evolve{values.heal_threshold, values.infect_threshold,
                values.death_threshold};

  std::cout
      << "\u001b[33;1m"
      << "\n(!)"
      << "\u001b[37;1m"
      << " Now that you have set the input configurations you can go to the "
         "file Input_Config/INPUT_BOARD.txt. \nHere you can draw the initial "
         "population configuration from which the epidemic will start, adding "
         "\"Susceptibles\", \"Infected\", \"Recovered\" and \"Dead\" people. "
         "You can also personalize the map by adding \"Walls\". \nHere is the "
         "legend of the symbols you can use in the board:\n# = Wall\n* = "
         "Susceptible\n+ = Infected\nx = Recovered\nX = Dead\nYou can also "
         "start with a default input file: to do that select one file from the "
         "folder Input_Files (These are only for the default 70x20 boards! "
         "Don't forget to RENAME them \"INPUT_BOARD.txt\" when you put them in "
         "the Input_Config folder!).\nWhen you are ready press Enter to "
         "continue.";

  std::getline(std::cin, line);

  Fill_Board_From_Input(board);
  board.Draw();

  std::cout << "\u001b[33;1m"
            << "\n(!)"
            << "\u001b[37;1m"
            << " This is your input board, to start the epidemic evolution "
               "press Enter.\n";

  std::getline(std::cin, line);

  Board next = board;

  std::ofstream os{"Output_Files/OUTPUT.txt"};
  os << "Time" << '\t' << "Suscep." << '\t' << "Infect." << '\t' << "Recov."
     << '\t' << "Dead" << '\n';

  int t = 1; // Time of the epidemic evolution
  int N_Susceptible = board.count_Susceptible();
  int N_Infected = board.count_Infected();
  int N_Recovered = board.count_Recovered();
  int N_Dead = board.count_Dead();

  os << t << '\t' << N_Susceptible << '\t' << N_Infected << '\t' << N_Recovered
     << '\t' << N_Dead << '\n';

  // Main cycle of the program: it is used to update the epidemic situation
  // and to write on the OUTPUT.txt file
  for (t = 2; board.count_Infected() != 0; ++t) {
    next = evolve(board, t);
    step(next);
    next.Draw();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    board = next;

    N_Susceptible = board.count_Susceptible();
    N_Infected = board.count_Infected();
    N_Recovered = board.count_Recovered();
    N_Dead = board.count_Dead();
    os << t << '\t' << N_Susceptible << '\t' << N_Infected << '\t'
       << N_Recovered << '\t' << N_Dead << '\n';
  }

  os.close();

  std::cout << "\u001b[33;1m"
            << "\n(!)"
            << "\u001b[37;1m"
            << " The epidemic is over. An input file has been created in the "
               "folder Output_Files. You can now graph your results using a "
               "graphing program!"
            << '\n';
}

