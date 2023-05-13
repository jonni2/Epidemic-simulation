#ifndef INPUT_HPP
#define INPUT_HPP

#include "../Board_Utilities/board.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

struct Input_Values {
  int base;
  int height;
  double quarantine_threshold;
  double heal_threshold;
  double infect_threshold;
  double death_threshold;
};

// This function creates the default input file
// to start the program, if it is not present in
// the folder
inline void default_input_file() {
  std::ofstream os;
  os.open("Input_Config/SETTINGS.txt");

  os << "base 70\n";
  os << "height 20\n\n";
  os << "quarantine_threshold 1.\n\n";
  os << "heal_threshold 2.5\n";
  os << "infect_threshold 0.069\n";
  os << "death_threshold 0.75";
  os.close();

  os.open("Input_Config/INPUT_BOARD.txt");

  // Creating the default board, with base=70, height=20
  for (int i = 1; i != (70 + 2) * (20 + 2) + 1; ++i) {
    if (i < 72 || i > 21 * 72 || (i - 1) % 72 == 0) {
      os << '#';
    } else if (i % 72 == 0) {
      os << '#' << '\n';
    } else {
      os << ' ';
    }
  }

  os.close();
}

// This function is used to check if
// the input file is correct and readable
// by the program
inline void check_input_file() {
  std::ifstream is;
  // Checking the program Settings
  is.open("Input_Config/SETTINGS.txt");
  std::string parameter;
  int base;
  int height;
  double value;

  is >> parameter >> base;
  if(parameter != "base" || base <= 0) {
    throw std::runtime_error{"The settings are not correct! Check the parameter \"base\" in the file Input_Config/SETTINGS.txt"};
  } else if(base > 175) {
    throw std::runtime_error{"The parameter \"base\" in the file SETTINGS.txt is too big!"};
  }
  
  is >> parameter >> height;
  if(parameter != "height" || height <= 0) {
    throw std::runtime_error{"The settings are not correct! Check the parameter \"height\" in the file Input_Config/SETTINGS.txt"};
  } else if(height > 175) {
    throw std::runtime_error{"The parameter \"height\" in the file SETTINGS.txt is too big!"};
  }
  
  is >> parameter >> value;
  if(parameter != "quarantine_threshold" || value < 0) {
    throw std::runtime_error{"The settings are not correct! Check the parameter \"quarantine\" in the file Input_Config/SETTINGS.txt"};
  }
  
  is >> parameter >> value;
  if(parameter != "heal_threshold" || value < 0) {
    throw std::runtime_error{"The settings are not correct! Check the parameter \"heal_threshold\" in the file Input_Config/SETTINGS.txt"};
  }
  
  is >> parameter >> value;
  if(parameter != "infect_threshold" || value < 0) {
    throw std::runtime_error{"The settings are not correct! Check the parameter \"infect_threshold\" in the file Input_Config/SETTINGS.txt"};
  }
  
  is >> parameter >> value;
  if(parameter != "death_threshold" || value < 0) {
    throw std::runtime_error{"The settings are not correct! Check the parameter \"death_threshold\" in the file Input_Config/SETTINGS.txt"};
  }

  is.close();

  // Checking the input board
  is.open("Input_Config/INPUT_BOARD.txt");
  std::string line;
  int count_lines = 0;
  while (std::getline(is, line)) {
    // We use static_cast because otherwise a warning of
    // comparison between signed and unsigned integer would
    // be generated
    if (static_cast<int>(line.size()) != base + 2) {
      break;
    }
    ++count_lines;
  }
  if (count_lines != height + 2) {
    // If the input board is NOT CORRECT the input board is RE-CREATED
    std::cout << "\u001b[31;1m" << "\n(!)" << "\u001b[37;1m" << " The previous input board in \"INPUT_BOARD.txt\" was not correct and has been re-created\n";
    std::ofstream os;
    os.open("Input_Config/INPUT_BOARD.txt");

    for (int i = 1; i != (base + 2) * (height + 2) + 1; ++i) {
      if (i < base + 2 || i > (height + 1) * (base + 2) ||
          (i - 1) % (base + 2) == 0) {
        os << '#';
      } else if (i % (base + 2) == 0) {
        os << '#' << '\n';
      } else {
        os << ' ';
      }
    }
    os.close();
  }
  is.close();
}

// This function is used to read from input file
inline Input_Values read_input() {

  std::string parameter;
  int base;
  int height;

  double quarantine_threshold;

  double heal_threshold;
  double infect_threshold;
  double death_threshold;

  std::ifstream is;
  is.open("Input_Config/SETTINGS.txt");

  is >> parameter >> base;
  is >> parameter >> height;
  is >> parameter >> quarantine_threshold;
  is >> parameter >> heal_threshold;
  is >> parameter >> infect_threshold;
  is >> parameter >> death_threshold;

  is.close();

  return Input_Values{base,           height,           quarantine_threshold,
                      heal_threshold, infect_threshold, death_threshold};
}

// This function is used to CREATE a board starting
// from the INPUT_BOARD.txt
inline void Fill_Board_From_Input(Board &board) {
  check_input_file();
  std::ifstream is;
  is.open("Input_Config/INPUT_BOARD.txt");
  std::string line;
  std::getline(is, line); // The FIRST Row is Border and won't be used
  for (int i = 1; i != board.SizeColumn() + 1; ++i) {
    std::getline(is, line);
    for (int j = 1; j != board.SizeRow() + 1; ++j) {
      switch (line[j]) {
      case '*':
        board(i, j) = State::Susceptible;
        break;
      case '+':
        board(i, j) = State::Infected;
        break;
      case 'x':
        board(i, j) = State::Recovered;
        break;
      case 'X':
        board(i, j) = State::Dead;
        break;
      // With the following case we allow the user to build his own "map"
      case '#':
        board(i, j) = State::Border;
        break;
      case ' ': break;
      default:
        throw std::runtime_error{"The input board is not correct: check the file Input_Config/INPUT_BOARD.txt"};
      }
    }
  }

  is.close();
}

#endif

