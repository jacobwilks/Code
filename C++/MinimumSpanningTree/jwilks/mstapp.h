/*
*  @file mstapp.h
*
*  @brief
*   Creates a Minimum Spanning Tree Graph and holds main function that runs
*   the entire program.
*
*
*  @author Jacob W
*  @date 3/30/18
*/

#ifndef __MSTAPP_H__
#define __MSTAPP_H__

#include "graph.h"
#include "minpriority.h"



class MSTapp{
  public:
    int main(); //program runner
  private:
    Graph myGraph; //graph used to hold Tree that is built
};

#endif
