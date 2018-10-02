//triangle.h
//wilks,jacob
//jwilks

#include <iostream>
#include <string>
#include <vector>
#include "grid.h"

using namespace std;

//constructor that creates an empty grid full of spaces
Grid::Grid(){
  //integers to set guidlines for the grid
  m_w=60;
  m_h=24;

  //make an empty grid of spaces
  for (int i=0; i<m_h; i++)
  {
    for (int j=0; j<m_w; j++)
    {
      grid[j][i] = ' ';
    }
  }
}

//function to print entire grid
void Grid::print()
{
  for (int i=0; i<m_h; i++)
  {
    for (int j=0; j<m_w; j++)
    {
      cout<<grid[j][i];
    }
    cout<<endl;
  }
}

void Grid::set(int x, int y, char c)
{
  //checks to make sure spots are inside grid.
  //and does nothing if not in spot.
  if (x < 0 || x > m_w || y < 0 || y>m_h)
    return;

    //sets that spot to the character passed in
    grid[x][y] = c;
}
