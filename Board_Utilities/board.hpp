#ifndef BOARD_HPP
#define BOARD_HPP

//This file, together with board.cpp, contains the 
//implementation of the class Board, which represents
//the space of the epidemic, populated by its inhabitants: the cells.
#include <cassert>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/*
LEGEND of the Board:
The grid is treated like a MATRIX:
i = Row index
j = Column index
       j
    ########
    #  +   #
i-> #   *  #
    #x   * #
    ########
*/

//This enum represents the possible states of each cell
enum class State : char {
  Susceptible = '*',
  Infected = '+',
  Recovered = 'x',
  Dead = 'X',
  Off = ' ',
  Border = '#',
  MoveS,
  MoveI
};

//This class represents the whole space populated by the cells
class Board {
private:
  std::vector<State> lines_;
  int base_;   //base of the grid
  int height_; //height of the grid

public:
  Board(int base, int height); //Class Constructor

  //Manipulate and modify the States of the board
  State operator()(int i, int j) const;

  State &operator()(int i, int j);

  //Draw on Terminal
  void Draw() const;

  //See Board characteristics from outside the class
  int SizeRow() const { return base_; }
  int SizeColumn() const { return height_; }
  int Size() const { return (base_ + 2) * (height_ + 2); }

  //Count the cells in a specific state
  int count_All() const;
  int count_Susceptible() const;
  int count_Infected() const;
  int count_Recovered() const;
  int count_Dead() const;

  //Function used to update from States "MoveI", "MoveS"
  //respectively to "Infected" and "Susceptible"
  void refresh_state();

};

#endif








