//enter info
//square.h
//wilks,jacob
//jwilks

#ifndef SQUARE_H
#define SQUARE_H

#include "grid.h"
#include "shape.h"
#include <iostream>

using namespace std;

//class square that uses public inheritance on Shape
class Square: public Shape{
private:
  //used for size of square
  double s;
public:
  //constuctor that takes in three ints, coordinates and the size
  //and deconstuctor
  Square(int,int,int);
  ~Square(){}
 
  //draw function to override the virtual one in shape
  void draw(Grid &grid);
};
#endif
