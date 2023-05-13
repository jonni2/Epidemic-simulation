#include "../../Board_Utilities/board.hpp"
#include "../doctest.h"
#include <random>

TEST_CASE("Testing board construction") {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> value(1, 100);
  Board test_board{10, 20};
  // Testing the dimensions and size
  CHECK(test_board.Size() == 264); // 264 = (10+2)*(20+2)
  CHECK(test_board.SizeRow() == 10);
  CHECK(test_board.SizeColumn() == 20);

  // Check if the borders are correctly constructed
  Board const &const_test_board = test_board;

  for (int i = 0; i != const_test_board.SizeColumn() + 2; ++i) {
    for (int j = 0; j != const_test_board.SizeRow() + 2; ++j) {
      if ((i == 0) || (i == const_test_board.SizeColumn() + 1) ||
          (j % (const_test_board.SizeRow() + 2) == 0) ||
          ((j + 1) % (const_test_board.SizeRow() + 2) == 0)) {
        CHECK(const_test_board(i, j) == State::Border);
      } else {
        CHECK(const_test_board(i, j) == State::Off);
      }
    }
  }

  // Generate 100 RANDOM boards to check:
  int base;
  int height;
  
  for (int index = 1; index != 101; ++index) {
    base = value(generator);
    height = value(generator);
    Board test_board1{base, height};
    Board const& const_test_board1 = test_board1;
    CHECK(test_board1.SizeRow() == base);
    CHECK(test_board1.SizeColumn() == height);
    CHECK(test_board1.Size() == (base+2)*(height+2));
    for (int i = 0; i != const_test_board1.SizeColumn() + 2; ++i) {
      for (int j = 0; j != const_test_board1.SizeRow() + 2; ++j) {
        if ((i == 0) || (i == const_test_board1.SizeColumn() + 1) ||
            (j % (const_test_board1.SizeRow() + 2) == 0) ||
            ((j + 1) % (const_test_board1.SizeRow() + 2) == 0)) {
          CHECK(const_test_board1(i, j) == State::Border);
        } else {
          CHECK(const_test_board1(i, j) == State::Off);
        }
      }
    }
  }
}

TEST_CASE("Testing board public functions") {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> value(1, 100);
  std::uniform_int_distribution<> choice(1, 4);

  // Generate 100 RANDOM boards to test
  for (int index = 1; index != 101; ++index) {
    Board test_board{100, 100};
    for (int index2 = 1; index2 != 101; ++index2) {
      int i = value(generator);
      int j = value(generator);
      test_board(i, j) = State::Infected;
    }
    // One can verify that is we put only "<" instead of "<=" the tests will
    // fail!
    CHECK(test_board.count_Infected() <= 100);
    CHECK(test_board.count_All() <= 100);
  }

  {
    Board test_board{100, 100};
    for (int i = 1; i != test_board.SizeColumn() + 1; ++i) {
      int j = value(generator);
      int state = choice(generator);
      switch (state) {
      case 1:
        test_board(i, j) = State::Susceptible;
        break;
      case 2:
        test_board(i, j) = State::Infected;
        break;
      case 3:
        test_board(i, j) = State::Recovered;
        break;
      case 4:
        test_board(i, j) = State::Dead;
        break;
      }
    }
    CHECK(test_board.count_All() == 100);
  }

  Board test_board{70, 20};
  test_board(1, 1) = State::Susceptible;
  test_board(2, 5) = State::Susceptible;
  test_board(1, 8) = State::Susceptible;
  test_board(5, 10) = State::Susceptible;
  test_board(10, 5) = State::Infected;
  test_board(12, 10) = State::Infected;
  test_board(12, 10) = State::Infected; // SAME as the previous!
  test_board(10, 15) = State::Dead;
  test_board(15, 1) = State::Recovered;
  test_board(20, 70) = State::Border;
  test_board(20, 69) = State::Border;

  CHECK(test_board.count_All() == 8);
  CHECK(test_board.count_Infected() == 2);
  CHECK(test_board.count_Susceptible() == 4);
  CHECK(test_board.count_Recovered() == 1);
  CHECK(test_board.count_Dead() == 1);

  test_board(1, 1) = State::Off;   // S
  test_board(2, 5) = State::Off;   // S
  test_board(1, 8) = State::Off;   // S
  test_board(12, 10) = State::Off; // I
  test_board(10, 15) = State::Off; // D

  CHECK(test_board.count_All() == 3);
  CHECK(test_board.count_Susceptible() == 1);
  CHECK(test_board.count_Infected() == 1);
  CHECK(test_board.count_Dead() == 0);
  CHECK(test_board.count_Recovered() == 1);
}

TEST_CASE("Testing board.refresh_state()") {
  Board test_board{80, 100};
  test_board(1, 1) = State::MoveI;
  test_board(1, 10) = State::MoveI;
  test_board(1, 80) = State::MoveI;
  test_board(2, 80) = State::MoveI;
  test_board(3, 1) = State::MoveI;
  test_board(3, 57) = State::MoveI;
  test_board(3, 79) = State::MoveI;
  test_board(4, 7) = State::MoveI;
  test_board(4, 17) = State::MoveS;
  test_board(4, 18) = State::MoveS;
  test_board(4, 32) = State::MoveS;
  test_board(4, 58) = State::MoveS;
  test_board(17, 17) = State::MoveS;
  test_board(57, 1) = State::MoveS;
  test_board(68, 72) = State::MoveS;
  test_board(100, 80) = State::MoveS;
  test_board(100, 1) = State::Infected;

  CHECK(test_board.count_All() == 1);
  CHECK(test_board.count_Susceptible() == 0);
  CHECK(test_board.count_Infected() == 1);
  CHECK(test_board.count_Recovered() == 0);
  CHECK(test_board.count_Dead() == 0);

  test_board.refresh_state();

  CHECK(test_board.count_All() == 17);
  CHECK(test_board.count_Susceptible() == 8);
  CHECK(test_board.count_Infected() == 9);
  CHECK(test_board.count_Recovered() == 0);
  CHECK(test_board.count_Dead() == 0);

  for (int i = 1; i != test_board.SizeColumn() + 1; ++i) {
    for (int j = 1; j != test_board.SizeRow() + 1; ++j) {
      if (test_board(i, j) != State::Off) {
        test_board(i, j) = State::Off;
      }
    }
  }
  CHECK(test_board.count_All() == 0);
  CHECK(test_board.count_Susceptible() == 0);
  CHECK(test_board.count_Infected() == 0);
  CHECK(test_board.count_Recovered() == 0);
  CHECK(test_board.count_Dead() == 0);
}
