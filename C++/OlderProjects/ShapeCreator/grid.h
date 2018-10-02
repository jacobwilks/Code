///grid.h
//wilks,jacob
//jwilks

#include <iostream>
#include <string>
#include <vector>

#ifndef GRID_H
#define GRID_H
using namespace std;

class Grid{

private:
  //makes the grid the exact size that is needed.
  char grid[60][24];

public:
  //constuctor and deconstuctor
  Grid();
  ~Grid(){}
  //will be used to set a character at a certain location
  void set(int,int,char);
  //prints out grid row by row
  void print();
  //variables to hold max width and max height
  int m_w;
  int m_h;
};
#endif
