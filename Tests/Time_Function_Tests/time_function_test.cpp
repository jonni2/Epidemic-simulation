#include "../../Board_Evolution/time_function.hpp"
#include "../../Board_Utilities/board.hpp"
#include "../doctest.h"

TEST_CASE("Testing some values with a calculator") {
  Board test_board{10, 10};
  test_board(1, 1) = State::Susceptible;
  test_board(1, 2) = State::Infected;
  test_board(2, 2) = State::Infected;
  test_board(3, 2) = State::Susceptible;

  CHECK(gamma_t(1) == 0);
  CHECK(gamma_t(2) == doctest::Approx(0.693).epsilon(0.001));
  CHECK(gamma_t(5) == doctest::Approx(1.609).epsilon(0.001));
  CHECK(gamma_t(20) == doctest::Approx(2.995).epsilon(0.001));
  CHECK(gamma_t(42) == doctest::Approx(3.737).epsilon(0.001));

  CHECK(beta_inf(test_board, 1, 1) == 0.25);
  CHECK(beta_inf(test_board, 1, 2) == 0.125);
  CHECK(beta_inf(test_board, 1, 3) == 0.25);
  CHECK(beta_inf(test_board, 3, 1) == 0.125);
  CHECK(beta_inf(test_board, 10, 10) == 0);

  CHECK(quarantine(test_board) == 0.5);

  test_board(4, 1) = State::Infected;
  test_board(4, 2) = State::Infected;

  CHECK(beta_inf(test_board, 3, 2) == 0.375);

  CHECK(quarantine(test_board) == doctest::Approx(0.66666).epsilon(0.00001));
}
