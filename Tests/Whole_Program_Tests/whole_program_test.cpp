#include "../../Board_Evolution/evolve.hpp"
#include "../../Board_Evolution/step.hpp"
#include "../../Board_Utilities/board.hpp"
#include "../doctest.h"
#include "input.hpp"
#include <chrono>
#include <thread>

TEST_CASE(
    "Testing an example program: Tests/Whole_Program_Tests/Input_Config") {
  std::string settings_path =
      "Tests/Whole_Program_Tests/Input_Config/SETTINGS.txt";
  std::string input_board_path =
      "Tests/Whole_Program_Tests/Input_Config/INPUT_BOARD.txt";
  Input_Values values = read_input(settings_path);
  CHECK(values.base == 100);
  CHECK(values.height == 10);
  CHECK(values.quarantine_threshold == 1.);
  CHECK(values.heal_threshold == 2.7);
  CHECK(values.infect_threshold == 0.04);
  CHECK(values.death_threshold == 0.65);

  Board test_board{values.base, values.height};
  CHECK(test_board.SizeRow() == 100);
  CHECK(test_board.SizeColumn() == 10);

  Step step{values.quarantine_threshold};
  Evolve evolve{values.heal_threshold, values.infect_threshold,
                values.death_threshold};

  Fill_Board_From_Input(test_board, settings_path, input_board_path);
  CHECK(test_board.count_All() == 126);
  CHECK(test_board.count_Infected() == 2);
  CHECK(test_board.count_Susceptible() == 116);
  CHECK(test_board.count_Recovered() == 3);
  CHECK(test_board.count_Dead() == 5);
  CHECK(test_board(3, 7) == State::Dead);
  CHECK(test_board(5, 24) == State::Susceptible);

  CHECK(beta_inf(test_board, 1, 1) == 0);
  CHECK(beta_inf(test_board, 5, 24) == 0.125);
  CHECK(near_infect(test_board, 5, 24) == 1);
  CHECK(quarantine(test_board) == doctest::Approx(0.0158).epsilon(0.0001));

  Board test_next = test_board;
  int initial_all = test_board.count_All();
  for (int t = 1; test_board.count_Infected() != 0; ++t) {
    test_next = evolve(test_board, t);
    step(test_next);
    test_next.Draw(); // Graphic test
    //The Susceptibles can only DECREASE
    CHECK(test_next.count_Susceptible() <= test_board.count_Susceptible());
    //The Dead cells can only INCREASE
    CHECK(test_next.count_Dead() >= test_board.count_Dead());
    //The Recovered cells can only INCREASE
    CHECK(test_next.count_Recovered() >= test_board.count_Recovered());
    test_board = test_next;
    CHECK(test_next.count_All() == initial_all);
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
}
