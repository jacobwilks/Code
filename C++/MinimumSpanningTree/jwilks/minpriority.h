/*
*  @file MinPriority.h
*
*  @brief
*   Creates a minimum priorty queue and necessary functions
*
*
*  @author Jacob W
*  @date 3/30/18
*/

#ifndef __MINPRIORITY_H
#define __MINPRIORITY_H

#include <string>
#include <list>
#include <vector>
#include <iostream>

using std::string;
using std::list;
using std::vector;

class MinPriority {

public:
   MinPriority(); //constructor
   ~MinPriority();
   void insert(string, int); //insert into queue
   void decreaseKey(string,int);//decrease inserted key
   string extractMin(); //pull minimum value from queue
   bool isMember(string); //determines if id is inside minHeap
private:
    class Element {
     public:
       Element(string,int);
       string id;
       int key;
    };
    vector<Element*> minHeap; //minheap
    void buildMinHeap(); //creates a minimum heap
    void minHeapify(int); //ensures roots of nodes and itself are min heaps
    int parent(int); //value of nodes parent
    int left(int);   //value of node to the left of selected node
    int right(int);  //value of node to the right of selected node
};

#endif
