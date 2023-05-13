#include "../../Board_Evolution/evolve.hpp"
#include "../../Board_Evolution/step.hpp"
#include "../../Board_Utilities/board.hpp"
#include "../doctest.h"
#include <random>

//ATTENTION: MAY TAKE A WHILE TO EXECUTE THIS TESTS!!

TEST_CASE("Testing Step construction") {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::normal_distribution<double> negative(-100, 50);
  CHECK_THROWS(Step step{-1});
  CHECK_THROWS(Step step1{-2.5});

  for (int i = 1; i != 101; ++i) {
    double parameter = negative(gen);
    if (parameter > 0) {
      parameter = -parameter;
    }
    CHECK_THROWS(Step step2{parameter});
  }
}

TEST_CASE("Testing Step Cell conservation") {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_int_distribution<> dimension(1, 100);
  std::uniform_int_distribution<> choice(1, 4);
  std::uniform_real_distribution<> quarantine(0., 1.);
  int base;
  int height;
  double quar_value;

  // Testing 100 RANDOM boards
  for (int index = 1; index != 101; ++index) {
    base = dimension(gen);
    height = dimension(gen);
    quar_value = quarantine(gen);
    Board test_board{base, height};
    Step step{quar_value};
    CHECK(base == test_board.SizeRow());
    CHECK(height == test_board.SizeColumn());
    // Board random filling cycle which will fill maximum 100 cells
    for (int index2 = 1; index2 != 101; ++index2) {
      int i = dimension(gen);
      int j = dimension(gen);
      if (i < test_board.SizeColumn() + 1 && j < test_board.SizeRow() + 1) {
        int state = choice(gen);
        switch (state) {
        case 1:
          test_board(i, j) = State::Susceptible;
        case 2:
          test_board(i, j) = State::Infected;
        case 3:
          test_board(i, j) = State::Recovered;
        case 4:
          test_board(i, j) = State::Dead;
        }
      }
    }
    int initial_all = test_board.count_All();
    for (int index3 = 1; index3 != 101; ++index3) {
      step(test_board);
      CHECK(test_board.count_All() == initial_all);
    }
  }
}

TEST_CASE("Testing Evolve and Step Cell conservation") {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_int_distribution<> dimension(1, 100);
  std::uniform_int_distribution<> choice(1, 4);
  std::uniform_real_distribution<> quarantine(0., 1.);
  std::uniform_real_distribution<> h_threshold(1., 5.);
  std::uniform_real_distribution<> threshold(0., 1.);
  int base;
  int height;
  double quarantine_threshold;
  double heal_threshold;
  double infect_threshold;
  double dead_threshold;

  // Testing 50 RANDOM boards
  for (int index = 1; index != 51; ++index) {
    base = dimension(gen);
    height = dimension(gen);
    quarantine_threshold = quarantine(gen);
    heal_threshold = h_threshold(gen);
    infect_threshold = threshold(gen);
    dead_threshold = threshold(gen);

    Board test_board{base, height};
    Board test_next = test_board;
    Step step{quarantine_threshold};
    Evolve evolve{heal_threshold, infect_threshold, dead_threshold};

    CHECK(base == test_board.SizeRow());
    CHECK(height == test_board.SizeColumn());
    // Board random filling cycle which will fill maximum 100 cells
    for (int index2 = 1; index2 != 100; ++index2) {
      int i = dimension(gen);
      int j = dimension(gen);
      if (i < test_board.SizeColumn() + 1 && j < test_board.SizeRow() + 1) {
        int state = choice(gen);
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
    }
    int initial_all = test_board.count_All();

    // Testing if the number of cells is constant during 
    // complete epidemic evolutions
    for (int t = 1; test_board.count_Infected() != 0; ++t) {
      test_next = evolve(test_board, t);
      step(test_next);
      CHECK(test_next.count_All() == initial_all);
      test_board = test_next;
    }
  }
}

// With the following TEST_CASE we want to test that, with the
// step() function, the cells can move ONLY towards the 8 neighbour cells
TEST_CASE("Testing if cells move ONLY in their neighborhood") {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_int_distribution<> choice(0, 1);
  std::uniform_real_distribution<> quarantine_value(0., 1.);

  for (int index = 1; index != 100; ++index) {
    Board test_board{10, 10};
    Step step{quarantine_value(gen)};

    int state = choice(gen);
    switch (state) {
    case 0:
      test_board(5, 5) = State::Susceptible;
      break;
    case 1:
      test_board(5, 5) = State::Infected;
      break;
    }

    if (test_board(5, 5) == State::Susceptible) {
      step(test_board);
      for (int i1 = 5 - 2; i1 != 5 + 3; ++i1) {
        for (int j1 = 5 - 2; j1 != 5 + 3; ++j1) {
          if (i1 == 5 - 2 || i1 == 5 + 2 || j1 == 5 + 2 || j1 == 5 - 2) {
            CHECK(test_board(i1, j1) == State::Off);
          } else if (i1 == 5 - 1 || i1 == 5 + 1 || j1 == 5 + 1 || j1 == 5 - 1) {
            bool check = test_board(i1, j1) == State::Off ||
                         test_board(i1, j1) == State::Susceptible;
            CHECK(check == true);
          }
          CHECK(test_board.count_Susceptible() == 1);
          CHECK(test_board.count_All() == 1);
        }
      }
    } else if (test_board(5, 5) == State::Infected) {
      step(test_board);
      for (int i1 = 5 - 2; i1 != 5 + 3; ++i1) {
        for (int j1 = 5 - 2; j1 != 5 + 3; ++j1) {
          if (i1 == 5 - 2 || i1 == 5 + 2 || j1 == 5 + 2 || j1 == 5 - 2) {
            CHECK(test_board(i1, j1) == State::Off);
          } else if (i1 == 5 - 1 || i1 == 5 + 1 || j1 == 5 + 1 || j1 == 5 - 1) {
            bool check = test_board(i1, j1) == State::Off ||
                         test_board(i1, j1) == State::Infected;
            CHECK(check == true);
          }
          CHECK(test_board.count_Infected() == 1);
          CHECK(test_board.count_All() == 1);
        }
      }
    }
  }
}


