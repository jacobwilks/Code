//square.cpp
//wilks,jacob
//jwilks

#include "square.h"
#include <iostream>
#include "shape.h"
#include "grid.h"

using namespace std;


//constuctor that takes in three parameters
Square::Square(int x, int y, int size):Shape(x,y), s(size){}

//draw function that will create the first row then go down and place the stars in the proper order based on the size
//so it stays in the correct format.
//
void Square::draw(Grid &grid){

  //run as many times as user put in for size
  for (int i=0; i< s; i++)
  {
    //first row will go as many times as user put in and fill in each slot
    if (i == 0)
    {
      for (int j=0; j<s; j++)
        grid.set((j + m_x), (m_y), '*');
    }
    //if this is last row it will place as many times as user put in
    else if (i == (s - 1))
    {
      for (int j = 0; j < s; j++)
        grid.set(( j + m_x), (i+m_y), '*');
    }
    //will set the "walls" of the square when its not first or last row
    else{
      grid.set((m_x), (i+m_y), '*');
      grid.set((m_x + s - 1), (i+m_y), '*');
    }
  }
}


