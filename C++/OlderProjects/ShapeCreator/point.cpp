//point.cpp
//wilks,jacob
//jwilks



#include "point.h"
#include <iostream>
#include "shape.h"
#include "grid.h"

using namespace std;

//constuctor that takes in the coordinates and what character to draw
Point::Point(int x, int y, char c): Shape(x,y), tchar(c){}

//draw the selected character at m_x and m_y and return
void Point::draw(Grid &grid)
{
  grid.set((m_x), (m_y), (tchar));
  return;
}
