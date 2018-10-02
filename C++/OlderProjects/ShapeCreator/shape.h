///shape.h
//wilks,jacob
//jwilks

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "grid.h"

using namespace std;


class Shape {
  protected:
    //m_x and m_y will be used to hold location of where we will be setting the item.
    int m_x;
    int m_y;

  public:
    //constuctor and deconstuctor
    Shape(int, int);
    virtual void draw(Grid &grid) = 0;
    ~Shape();

};
#endif
