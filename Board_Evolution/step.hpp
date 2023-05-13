#ifndef STEP_HPP
#define STEP_HPP

#include "../Board_Utilities/board.hpp"
#include "time_function.hpp"
#include <cmath>
#include <random>

class Step {
private:
  std::mt19937 gen_step_;
  double quarantine_threshold_;

public:
  Step(double quarantine_threshold)
      : quarantine_threshold_{quarantine_threshold} {
    if (quarantine_threshold < 0) {
      throw std::runtime_error{"Invalid Step parameter!"};
    }
  }

  void operator()(Board &board);
};

#endif
