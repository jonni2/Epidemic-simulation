#ifndef EVOLVE_HPP
#define EVOLVE_HPP

#include "../Board_Utilities/board.hpp"
// #include "near_infect.hpp"
#include "time_function.hpp"
#include <cmath>
#include <random>
#include <stdexcept>

class Evolve {
private:
  std::mt19937 gen_evolve_;
  double heal_threshold_;
  double infect_threshold_;
  double death_threshold_;

public:
  Evolve(double h_thres, double i_thres, double d_thres)
      : heal_threshold_{h_thres}, infect_threshold_{i_thres}, death_threshold_{
                                                                  d_thres} {
    if (h_thres < 0 || i_thres < 0 || d_thres < 0) {
      throw std::runtime_error{"Invalid Evolve Parameters!"};
    }
  }

  Board operator()(Board const &curr, int t);
};

#endif
