//circle.cpp
//wilks,jacob
//jwilks




#include "circle.h"

#include <iostream>
#include "shape.h"
#include "grid.h"

using namespace std;

//constuctor that only takes in two parameters since size is fixed
Circle::Circle(int x, int y): Shape(x,y){}

void Circle::draw(Grid &grid)
{
  //draws a fixed circle where the top row is placed in row y
  //and the left side in col x

  //has a condition for each size so it will place two circles as top row
  for (int i=0; i<4; i++)
  {
    //top row it will set an o offset by one spot and two spots
    if (i==0)
    {
      grid.set((m_x +1), (i + m_y), 'o');
      grid.set((m_x +2), (i+m_y), 'o');
    }
    //for second row it will place an o at m_x then offset by three for walls of circle
    else if(i==1)
      {
        grid.set((m_x), (i+m_y), 'o');
        grid.set((m_x +3), (i+m_y), 'o');
      }
    else if(i==2)
    {
        grid.set((m_x), (i+m_y), 'o');
        grid.set((m_x +3), (i+m_y), 'o');
    }
    //bottom row
    else if(i==3)
    {
      grid.set((m_x +1), (i + m_y), 'o');
      grid.set((m_x +2), (i+m_y), 'o');
    }
  }
}
     
