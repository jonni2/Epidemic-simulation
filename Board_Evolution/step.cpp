#include "step.hpp"

// This function is used to MOVE the cells in the board:
// every cell can move towards its neighbour cells.
// The movement consists of swapping the initial cell with the
// final cell and it can happen only if the final cell is State::Off and
// if the quarantine allows it.
// The function moves, one by one, every cell.
// We use 2 boards because with the const_board we can call the operator() const
// and we need to keep trace of the modifications made to the board while
// the cells are moving.
// The function is of type void becaues otherwise we should create a copy of
// the board to return, which is not so useful.


void Step::operator()(Board& board) {
  Board const &const_board = board;
  std::uniform_int_distribution<> move(-1, 1);
  std::normal_distribution<double> random_factor(0.5, 0.1);

  // Like in a Matrix:
  // i = Row index
  // j = Column index
  for (int i = 1; i != const_board.SizeColumn() + 1; ++i) {
    for (int j = 1; j != const_board.SizeRow() + 1; ++j) {
      int movex = move(gen_step_);
      int movey = move(gen_step_);
      if ((const_board(i, j) == State::Susceptible) &&
          (const_board(i + movey, j + movex) == State::Off) &&
          (quarantine(const_board) * std::abs(random_factor(gen_step_)) < quarantine_threshold_)) {
        board(i + movey, j + movex) = State::MoveS;
        board(i, j) = State::Off;
      }
      else if ((const_board(i, j) == State::Infected) &&
          (const_board(i + movey, j + movex) == State::Off) &&
          (quarantine(const_board) * std::abs(random_factor(gen_step_)) < quarantine_threshold_)) {
        board(i + movey, j + movex) = State::MoveI;
        board(i, j) = State::Off;
      }
    }
  }
  board.refresh_state();
}


