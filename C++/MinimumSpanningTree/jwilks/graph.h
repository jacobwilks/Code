/*
*  @file graph.h
*
*  @brief
*   Creates a Graph and required classes to run graph in coordination with a
*   minPriorityQueue
*
*
*  @author Jacob W
*  @date 5/13/18
*/

#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "minpriority.h"
#include <algorithm>
using std::string;
using std::list;
using std::vector;
using std::map;

class Graph {
  private:
    class Vertex{
      public:
        string pi; //predecessor
        int key;
        Vertex(string,int); // Vertex constructor
    };
  class Neighbor{
    public:
      string name;
      int weight;
      Neighbor(string,int);//Neighbor Constructor
      bool operator<(const Neighbor& n) const { return name < n.name; }//JUDYS
  };
  public:
    Graph();
    //~Graph();
    MinPriority *minQ;
    map<string,Vertex*> vertices;
    map<string,vector <Neighbor> >adjList;
    void addVertex(string name);
    void addEdge(string from,string to,int weight);
    void mst(string start); //PRIMS MST
};

#endif
