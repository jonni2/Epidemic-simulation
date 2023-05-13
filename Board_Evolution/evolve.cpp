#include "evolve.hpp"

// This function is used to update the situation of the infections with the new
// Infected, Susceptibles, Recovered and Dead cells.


Board Evolve::operator()(Board const &curr, int t)
{
  Board next = curr;
  std::normal_distribution<double> random_factor(0.5, 0.1); //Random factor added to the epidemic
                                                            //evolution
  for (int i = 1; i != curr.SizeColumn() + 1; ++i) {
    for (int j = 1; j != curr.SizeRow() + 1; ++j) {
      switch (curr(i, j)) {
      case State::Susceptible: //Infection
        if (beta_inf(curr, i, j) * std::abs(random_factor(gen_evolve_)) > infect_threshold_) {
          next(i, j) = State::Infected;
        }
        break;

      case State::Infected: //Healing and Death
        if (gamma_t(t) * std::abs(random_factor(gen_evolve_)) > heal_threshold_) {
          next(i, j) = State::Recovered; }
        else if((std::abs(random_factor(gen_evolve_))> death_threshold_)) { 
          next(i, j) = State::Dead; }
        break;
      default: ;
      }
    }
  }

  return next;
}

