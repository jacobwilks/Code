//circle.h
//wilks,jacob
//jwilks

#ifndef CIRCLE_H
#define CIRCLE_H
#include "grid.h"
#include <iostream>
#include "shape.h"

using namespace std;

//uses inheritance on shape class
class Circle: public Shape {
  public:
    //constuctor that takes in two ints and deconstuctor to get rid of leftover variables
    Circle(int, int);
    ~Circle(){}

    //overridden function to use this classes draw instead of shapes
    void draw(Grid &grid);
 };
#endif
