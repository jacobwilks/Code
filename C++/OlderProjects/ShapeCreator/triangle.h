//triangle.h
//wilks,jacob
//jwilks

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "grid.h"
#include "shape.h"

using namespace std;

//public inheritance of shape class
class Triangle: public Shape{
  public:
    //constuctor and deconstuctor
    Triangle(int, int);
    ~Triangle(){}

    //draw function to override virtual function
    void draw(Grid &grid);
 };
#endif
