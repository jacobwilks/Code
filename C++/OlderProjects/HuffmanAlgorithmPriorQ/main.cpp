//main.cpp
//Jacob Wilks
//jwilks
#include<iostream>

#include<string>
#include<fstream>
#include <stdio.h>
using namespace std;
#include "priority_queue.h"
#include "tree.cpp"

int main(int argc, char *argv[]){
  
  
  //needed variables
  PriorityQueue<Node<char>*>pq; 
  int freq[256];
  string input = argv[1];
  string temp;
  ifstream in;
  int pqamount;
  int priority;
  int totalpriority;

  //check if file opened - if not output error message
  in.open(argv[1]);
  if (!in){
    cerr<<"ERROR: could not open file "<<input<<endl;
    return 1;
  }

  //initialize array
  for (int i=0; i<256; i++){
    freq[i]=0;
  }
  
  //frequency counter
  getline(in,temp);
  while (!in.eof()){

    for ( int i=0; i<temp.length(); i++){
      char ch = toupper(temp[i]);
      freq[(int)ch]++;
    }
    getline(in,temp);

  }//while

  //outputs frequency of characters and count how many unique nodes are made 
      for (int j=0; j<256; j++){ 
      if (freq[j] > 0){
      cout << (char)j << " " << freq[j]<<endl;
      Node<char> *temp = new Node<char>((char)j, NULL, NULL, freq[j]);
      pq.enqueue(temp, freq[j]);
      pqamount++;
      }
  }//for loop

     //idea behind this is make a new node of lowest amount, set to temp node and merge them until pq is 1
  while(pq.size() >1){
    Node<char> temp1 = pq.front();
    pq.dequeue();
    Node<char>temp2 = pq.front();
    pq.dequeue();
    totalpriority = temp1.priority + temp2.priority;
    Node<char>*merged = new Node<char>(pqamount, &temp1, &temp2, totalpriority);
    pq.enqueue(merged,totalpriority);
  }
  

}//main
