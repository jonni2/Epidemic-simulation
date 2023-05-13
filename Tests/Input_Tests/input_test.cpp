#include "../../Board_Evolution/near_infect.hpp"
#include "../../Board_Utilities/board.hpp"
#include "../doctest.h"
#include "input.hpp"
#include <fstream>
#include <iostream>
#include <string>

TEST_CASE("Testing default_input_file()") {
  default_input_file();
  std::ifstream is;
  is.open("Tests/Input_Tests/Input_Config/SETTINGS.txt");
  std::string parameter;
  int base;
  int height;
  double value;
  is >> parameter >> base;
  CHECK(parameter == "base");
  CHECK(base == 70);

  is >> parameter >> height;
  CHECK(parameter == "height");
  CHECK(height == 20);

  is >> parameter >> value;
  CHECK(parameter == "quarantine_threshold");
  CHECK(value == 0.05);

  is >> parameter >> value;
  CHECK(parameter == "heal_threshold");
  CHECK(value == 2.5);

  is >> parameter >> value;
  CHECK(parameter == "infect_threshold");
  CHECK(value == 0.069);

  is >> parameter >> value;
  CHECK(parameter == "death_threshold");
  CHECK(value == 0.75);
}

// HERE we check a MODIFIED version of the function
// check_input_file. We made it to be able to decide
// which file to open and test
TEST_CASE("Testing check_input_file()") {
  std::string path = "Tests/Input_Tests/Failure_Tests/SETTINGS1.txt";
  std::string input_board_path =
      "Tests/Input_Tests/Input_Config/INPUT_BOARD.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS2.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS3.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS4.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS5.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS6.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS7.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS8.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS9.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS10.txt"; // Used NULL value
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS11.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
  path = "Tests/Input_Tests/Failure_Tests/SETTINGS12.txt";
  CHECK_THROWS(check_input_file(path, input_board_path));
}

// HERE we check the same MODIFIED version of the function
// check_input_file
TEST_CASE("Testing read_input() and Fill_Board_From_Input") {
  std::string settings_path = "Tests/Input_Tests/Input_Config/SETTINGS.txt";
  std::string input_board_path =
      "Tests/Input_Tests/Input_Config/INPUT_BOARD1.txt";
  check_input_file(settings_path, input_board_path);
  Input_Values values = read_input(settings_path);
  CHECK(values.base == 70);
  CHECK(values.height == 20);
  CHECK(values.quarantine_threshold == 0.05);
  CHECK(values.heal_threshold == 2.5);
  CHECK(values.infect_threshold == 0.069);
  CHECK(values.death_threshold == 0.75);

  Board test_board{values.base, values.height};
  Fill_Board_From_Input(test_board, settings_path, input_board_path);
  CHECK(test_board.count_All() == 38);
  CHECK(test_board.count_Susceptible() == 29);
  CHECK(test_board.count_Infected() == 9);
  CHECK(test_board.count_Recovered() == 0);
  CHECK(test_board.count_Dead() == 0);
  CHECK(test_board(1, 1) == State::Susceptible);
  CHECK(test_board(1, 2) == State::Infected);
  CHECK(test_board(2, 22) == State::Susceptible);
  CHECK(near_infect(test_board, 1, 1) == 2);
  CHECK(near_infect(test_board, 2, 22) == 0);

  input_board_path = "Tests/Input_Tests/Input_Config/INPUT_BOARD2.txt";
  Fill_Board_From_Input(test_board, settings_path, input_board_path);
  CHECK(test_board.count_All() == 147);
  CHECK(test_board(5, 1) == State::Border);
  CHECK(test_board(5, 2) == State::Border);
  CHECK(test_board(5, 3) == State::Border);
  CHECK(test_board(5, 4) == State::Border);

  // Wrong input Symbols
  input_board_path = "Tests/Input_Tests/Input_Config/INPUT_BOARD3.txt";
  CHECK_THROWS(
      Fill_Board_From_Input(test_board, settings_path, input_board_path));
  // Correct symbols but wrong dimensions
  input_board_path = "Tests/Input_Tests/Input_Config/INPUT_BOARD4.txt";
  CHECK_THROWS(
      Fill_Board_From_Input(test_board, settings_path, input_board_path));
  // Correct symbols but wrong lines length
  input_board_path = "Tests/Input_Tests/Input_Config/INPUT_BOARD5.txt";
  CHECK_THROWS(
      Fill_Board_From_Input(test_board, settings_path, input_board_path));
}

TEST_CASE("Testing the whole procedure") {
  // Input board with base = 10, height = 8
  std::string settings_path = "Tests/Input_Tests/Input_Config/SETTINGS1.txt";
  std::string input_board_path =
      "Tests/Input_Tests/Input_Config/INPUT_BOARD4.txt";
  check_input_file(settings_path, input_board_path);
  Input_Values values = read_input(settings_path);
  Board test_board{values.base, values.height};
  CHECK(test_board.SizeRow() == values.base);
  CHECK(test_board.SizeColumn() == values.height);
  CHECK(test_board.SizeRow() == 10);
  CHECK(test_board.SizeColumn() == 8);
  // Testing how the board is Filled
  Fill_Board_From_Input(test_board, settings_path, input_board_path);
  // Counting cells
  CHECK(test_board.count_All() == 9);
  CHECK(test_board.count_Susceptible() == 4);
  CHECK(test_board.count_Infected() == 2);
  CHECK(test_board.count_Recovered() == 1);
  CHECK(test_board.count_Dead() == 2);

  // Verifying some cells States
  CHECK(test_board(1, 6) == State::Dead);
  CHECK(test_board(1, 9) == State::Infected);
  CHECK(test_board(3, 8) == State::Border);
  CHECK(test_board(7, 7) == State::Recovered);
  CHECK(test_board(1, 1) == State::Off);
}


