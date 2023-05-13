#ifndef TIME_FUNCTION_HPP
#define TIME_FUNCTION_HPP

#include <cassert>
#include <cmath>
#include <random>
#include "../Board_Utilities/board.hpp"
#include "near_infect.hpp"


// gamma is a factor that describes the probability that an Infected cell
// becomes Recovered.
inline double gamma_t(int time) {
  return std::log(time);
}

// beta is the probability of infection, it varies in function of the infected cells
// next to the selected cell
inline double beta_inf(Board const& board, int i, int j) {
  return ((near_infect(board, i, j))/8.);
}

// This function evaluates how many cells are infected
// It will be used to create a quarantine and establish if a cell can move
inline double quarantine(Board const& board) {
  int tot_inf = board.count_Infected();
  int tot_cells = board.count_All();
  return (static_cast<double> (tot_inf) / tot_cells);
}

#endif

