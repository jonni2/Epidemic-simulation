#include "board.hpp"

// Class Constructor
// Cycle used to fill the Board with empty and border cells when
// the Board is created
Board::Board(int base, int height) : base_{base}, height_{height} {
  for (int i = 0; i != (height_ + 2) * (base_ + 2); ++i) {
    if (i <= (base + 2) || i >= (base_ + 2) * (height_ + 1) ||
        (i % (base_ + 2)) == 0 || ((i + 1) % (base_ + 2)) == 0) {
      lines_.push_back(State::Border);
    } else {
      lines_.push_back(State::Off);
    }
  }
}

// READ-ONLY operator()
// i: Row index, j: Column index
State Board::operator()(int i, int j) const {
  assert((i >= 0 && i <= height_ + 1) && (j >= 0 && j <= base_ + 1));
  return lines_[i * (base_ + 2) + j];
}

// MODIFY Board operator()
State &Board::operator()(int i, int j) {
  assert(i >= 1 && i <= height_ && j >= 1 && j <= base_);
  return lines_[i * (base_ + 2) + j];
}

// Draw on Terminal
void Board::Draw() const {
  for (int i = 0; i != (base_ + 2) * (height_ + 2); ++i) {
    switch (lines_[i]) {
    case State::Infected:
      std::cout << "\u001b[31m" << static_cast<char> (lines_[i]); // Red Color
      break;
    case State::Recovered:
      std::cout << "\u001b[32m" << static_cast<char> (lines_[i]); // Green Color
      break;
    case State::Susceptible:
      std::cout << "\u001b[33m" << static_cast<char> (lines_[i]); // Yellow Color
      break;
    case State::Dead:
      std::cout << "\u001b[30;1m" << static_cast<char> (lines_[i]); // Black Color
      break;
    default:
      std::cout << "\u001b[37m" << static_cast<char> (lines_[i]); //"Neutral" Color
      break;
    }
    if (((i + 1) % (base_ + 2) == 0) && i != 0) {
      std::cout << '\n';
    }
  }
}

// Counting cells in the board
int Board::count_All() const {
  int n_cells = std::count_if(lines_.begin(), lines_.end(), [](State s) {
    return (s == State::Infected || s == State::Susceptible ||
            s == State::Recovered || s == State::Dead);
  });
  return n_cells;
}

int Board::count_Susceptible() const {
  int n_cells = std::count(lines_.begin(), lines_.end(), State::Susceptible);
  return n_cells;
}

int Board::count_Infected() const {
  int n_cells = std::count(lines_.begin(), lines_.end(), State::Infected);
  return n_cells;
}

int Board::count_Recovered() const {
  int n_cells = std::count(lines_.begin(), lines_.end(), State::Recovered);
  return n_cells;
}

int Board::count_Dead() const {
  int n_cells = std::count(lines_.begin(), lines_.end(), State::Dead);
  return n_cells;
}

// Function used to update from States "MoveI", "MoveS"
// respectively to "Infected" and "Susceptible"
void Board::refresh_state() {
  std::replace(lines_.begin(), lines_.end(), State::MoveI, State::Infected);
  std::replace(lines_.begin(), lines_.end(), State::MoveS, State::Susceptible);
}


