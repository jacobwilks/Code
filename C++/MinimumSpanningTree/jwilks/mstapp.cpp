/*
*  @file mstapp.cpp
*
*  @brief
*   Implements a Minimum Spanning Tree
*
*
*  @author Jacob W
*  @date 5/13/18
*/

#include <iostream>
#include <string>
#include "graph.h"
#include "minpriority.h"
#include "mstapp.h"
#include <sstream>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
  Graph myGraph;
  string v,to,from,root;
  int weight;
  getline(cin,v);
  std::istringstream iss(v);
  for ( string v; iss >> v;){
    myGraph.addVertex(v); //read in and add each vertex from first line
  }
    cin>>to>>from>>weight;
    root = to; // read in first edge and save it as the start of MST
    myGraph.addEdge(to,from,weight);
    while( !cin.eof()){ //reads in rest of edges
      cin>>to>>from>>weight;
      myGraph.addEdge(to,from,weight);
    }
  myGraph.mst(root); //starts mst
  return 0;
}
