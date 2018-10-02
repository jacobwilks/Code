//point.h
//wilks,jacob
//jwilks


#ifndef POINT_H
#define POINT_H
#include "shape.h"
#include<iostream>
#include"grid.h"


using namespace std;

//inheritance on Shape class
class Point: public Shape{
  private:
    //used to know what character to draw at location
    char tchar;
  public:
    //constuctor and deconstuctor
    Point(int,int,char);
    ~Point(){}
    void draw(Grid &grid);
};
#endif
