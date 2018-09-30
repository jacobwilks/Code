/**
 * @file MinPriorty.cpp
 *
 * @brief
 *    Implementation of a minimum priorty queue from CLRS Pseudo Code
 *
 *
 *
 *
 * @author Jacob W
 * @date 5/13/18
 */

#include "minpriority.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>
using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

/**
 * @brief   Constructor for MinpriorityQueue
 * @return  Nothing.
 *
 * Not using anymore just here to compile, get rid of before submitting
 */
MinPriority::MinPriority(){
}

/**
 * @brief   Constructor Element object
 * @param   id - id of new Element, Key - key of new element
 */
MinPriority::Element::Element(string id, int key){
  this->id = id;
  this->key = key;
}
/**
 * @brief   DeConstructor for MinpriorityQueue
 *
 * fill out once i make this
 */
MinPriority::~MinPriority(){

}
/**
 * @brief   Checks if the passed in id is inside the Heap
 * @return  True if id is inside heap, otherwise false
 *
 * Uses an iterator to search minHeap and determine if its in the heap.
 * If it is it returns true, otherwise once done searching returns false
 */
bool MinPriority::isMember(string id){
  vector<Element*>::iterator it;
  for (it=minHeap.begin(); it != minHeap.end(); it++){
    if((*it)->id == id){
      return true;
    }
  }
  return false;
}

/**
 * @brief   Builds Min Heap and maintains properties. Not being used with Q
 *
 * Not using anymore just here to compile, get rid of before submitting
 */
void MinPriority::buildMinHeap(){
  int temp = minHeap.size() / 2;
  for (int i = temp; i>=0; i--){
    minHeapify(i);
  }
}

/**
 * @brief   MinHeapify maintains minHeap properies recursively.
 * @param I = index of where minHeapify is being called.
 *
 * Pseudo Code
 *
 * Based heavily off Psuedo Code from CLRS. Adjusted since they use 1 as their
 * index. Searches through the minHeap and ensures that all properties are
 * still in place.
 */
void MinPriority::minHeapify(int i){
  int l = left(i);
  int r = right(i);
  int largest=0;
  if ( l <= int(minHeap.size()-1) && (minHeap[l]->key< minHeap[i]->key) ){
    largest = l;
  }
  else{
    largest = i;
  }
  if ( r <= int(minHeap.size()-1) && minHeap[r]->key < minHeap[largest]->key){
    largest = r;
  }
  if ( largest != i){
    std::swap(minHeap[i],minHeap[largest]);
    minHeapify(largest);
  }
}
/**
 * @brief   Inserts a new node into the MinpriorityQueue
 * @param   Id - Id of new element to be inserted
 * @param   Key - key of new element to be inserted
 *
 *
 * Based off CLRS Psuedo Code
 *
 * Inserts a new node after creating it into the minheap(priorityq)
 *  and then calls decreaseKey
 */

void MinPriority::insert(string id, int key){
  Element *temp = new Element(id,key);
  minHeap.push_back(temp);
  decreaseKey(temp->id,temp->key);
}

/**
 * @brief   Decrease the Key's value of chosen object
 * @param   Id - ID of object you want to change
 * @param   Key - The new value to be assigned to object
 *
 * Based off CLRS Psuedo Code
 *
 * Searches through the minHeap and finds the location of ID and saves it
 * to I. Then Sets the key's value of the found object to the new value
 * Then goes through a while loop to ensure it is still a minHeap
 */
void MinPriority::decreaseKey(string id, int key){
  int i=0;
  for ( int index=0; index< int(minHeap.size()); index++){
    if (minHeap[index]->id == id){
      i = index;
      minHeap[i]->key = key;
    }
  }
  while (i != 0 && minHeap[parent(i)]->key > minHeap[i]->key){
    std::swap(minHeap[i], minHeap[parent(i)]);
    i = parent(i);
  }
}



/**
 * @brief   Extracts the Minimum element from the minHeap ( first element)
 *          and returns the ID of the one that was extracted.
 * @return  Returns the ID of the extracted element from MinHeap
 *
 * Based off CLRS Pseudo Code
 *
 * If the minHeap is empty it returns a string containing "empty" that is used
 * inside MST to determine when minHeap is empty. Otherwise returns the ID of
 * the minimum element from the heap and extracts it. It also calls minHeapify
 * to ensure the minheap properties are still in place.
 */

string MinPriority::extractMin(){
    if (minHeap.size() <= 0){
      return "empty";
    }
    if (minHeap.size() == 1){ //test case
      minHeap.pop_back();
      return minHeap[0]->id;
    } //heap has items > 1 in it
      Element* min = minHeap[0];
      minHeap[0]=minHeap[minHeap.size()-1];
      minHeap.pop_back();
      minHeapify(0);
      return min->id;
}

/**
 * @brief   Returns the value of the parent of given element.
 * @param   i - index of element that you want to know parent of
 * @return  i - value of index's parent
 * Based off CLRS Pseudo Code
 */
int MinPriority::parent(int i){
  i = i/2;
  return i;
}
/**
 * @brief   Returns the value of the left element of given element.
 * @param   i - index of element that you want to know left of
 * @return  i - value of index's left element
 * Based off CLRS Pseudo Code
 */
int MinPriority::left(int i){
  i = 2*i;
  return i;
}

/**
 * @brief   Returns the value of the right element of given element.
 * @param   i - index of element that you want to know right of
 * @return  i - value of index's right element
 * Based off CLRS Pseudo Code
 */
int MinPriority::right(int i){
  i = 2*i+1;
  return i;
}
