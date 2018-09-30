/*
*  @file Graph.cpp
*
*  @brief
*   Contains functions that create and maintain the MST graph and the classes
*   that are used to build the graph ( edge and vertex).
*
*
*  @author Jacob W
*  @date 5/13/18
*/

#include "graph.h"
#include "minpriority.h"
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

/**
 * @brief   Vertex Constructor
 * @param   p - predecessor of new vertex, k - key of new vertex
 *
 */
Graph::Vertex::Vertex(string p, int k){
  pi = p;
  key= k;
}
/**
 * @brief   Neighbor Constructor
 * @param   n - name of new neighbor, weight of new neighbor
 *
 */
Graph::Neighbor::Neighbor(string n, int w){
  name = n;
  weight = w;
}
/**
 * @brief   Graph Constructor
 */
Graph::Graph(){
}

/**
 * @brief   Creating and adding an edge to the Adjcency List
 * @param   From - Where Edge is originating, To - where edge is connecting to
 * @param  Weight - Weight of new edge
 *

 * Creates a new neighbor object and initializes its values to; to and weight.
 * Places where it came from and where its going to inside the AdjList and
 * sorts the list.
 */
void Graph::addEdge(string from,string to,int weight){
  Neighbor temp(to,weight);
  adjList[from].push_back(temp);
  temp.name = from;
  adjList[to].push_back(temp);
  std::sort(adjList[from].begin(), adjList[from].end()); //Sort you gave us
}

/**
 * @brief   Creating and adding a vertex to the vertices list
 * @param   Name - Name of predecessor of new vertex
 *

 * Creates a pointer to a new Vertex object that is inialized with the pi
 * being value of the name passed in and id to zero. These will be adjusted
 * Then adds it to the list of vertices
 */
void Graph::addVertex(string name){
  Vertex* temp = new Vertex(name,0);
  vertices[name]=temp;
}

/**
 * @brief   Creating a Minimum Spanning Tree using Prim's Algorithm
 * @param   Where the MST will start from
 *
 * Based off CLRS Psuedo Code
 *
 *
 *
 * Creates a MinimumQ and initiates the values of all entered vertices to
 * infinity and predecessor to nil. Sets the key of the start to zero and
 * inserts each into the MinimumQ. Then goes through Prim's Algorithm finding
 * the Prims MST  until extractMin hits no element and returns empty. Once
 * the minHeap is empty the totalWeight is output.
 */
void Graph::mst(string start){
  //creates the minimum priority queue
  minQ = new MinPriority();
  int totalWeight=0; // weight of minimum spanning tree, gets incremented below
  for ( map<string,Vertex*>::iterator it = vertices.begin();
   it!= vertices.end(); it++){
    it->second->key = 101; // setting key to infinity
    it->second->pi="NIL"; // setting predecessor to nil
  }
  vertices[start]->key = 0;
  for ( map<string,Vertex*>::iterator it = vertices.begin();
   it!= vertices.end(); it++){
    //inserting them all into the minimum queue from vertices list
    minQ->insert(it->first,it->second->key);
  }
  string min = minQ->extractMin();
  while( min != "empty"){ //extractMin will return "empty" when empty
    cout << min << " " << vertices[min]->pi<< " "<<vertices[min]->key<<endl;
    for ( auto it = adjList[min].begin(); it!= adjList[min].end(); it++){
      if (minQ->isMember(it->name) && it->weight < vertices[it->name]->key){
        vertices[it->name]->pi = min;
        vertices[it->name]->key = it->weight;
        minQ->decreaseKey(it->name, it->weight);
      }
    }
    totalWeight = totalWeight + vertices[min]->key; //calculate weight of MST
    min = minQ->extractMin(); //keep extracting until returns "empty"
  }
  cout<<totalWeight<<endl; // once done output the weight
}
