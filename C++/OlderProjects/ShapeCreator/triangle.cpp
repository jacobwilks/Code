//triangle.cpp
//wilks,jacob
//jwilks

#include "triangle.h"
#include <iostream>
#include "shape.h"
#include "grid.h"

using namespace std;


Triangle::Triangle(int x, int y):Shape(x,y){}

//grid is by reference in each draw function so it returns updated grid
void Triangle::draw(Grid &grid){

  //i is less than three since its a triangle and will keep in format
  for (int i=0; i<3; i++){

    //this will set the first row with only one plus since i will be zero
    //then will set the second row with a space inbetween the +
    //then will fill the bottom row
    //uses +2 to set the top row or middle row
    if (i==0)
      grid.set((m_x+2), (i + m_y), '+');
    //uses +1 and +3 to skip the middle spot
    else if (i==1){
      grid.set((m_x +1), (i+m_y), '+');
      grid.set((m_x +3), (i+m_y), '+');
    }
    //fill the bottom row full of +
    else if(i==2){
      for (int j = 0; j<5; j++)
        grid.set((m_x + j), (i + m_y), '+');
    }
  }
}
