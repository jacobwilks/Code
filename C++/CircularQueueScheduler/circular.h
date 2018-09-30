/*
 * @file scheduler.h   Declaration of CircularQueue Class and nested Node Class
 *
 * @brief
 *    Creates a CircularQueue that is used for the round robin scheduling.
 *
 * @author Jacob Wilks
 * @date 2/10/18
 */

#ifndef CSCI_311_CIRCULAR_H
#define CSCI_311_CIRCULAR_H

#include <string>
#include "process.h"

class CircularQueue {
    public:
        CircularQueue();            //constructor
        ~CircularQueue();           //deconstuctor
        void append(const Process &p); //add a node to end of queue
        Process *getCurrent();     //returns current process if list isnt empty
        Process *getNext();        //returns next process if list isnt empty
    private:
      class Node {
          public:
            Node();                 //constructor
            Node(const Process& p); //constructor
            ~Node();                //deconstructor
            Node *next;             //next process of currently running one
            Node *prev;              //previous process of currently running one
            Process *data;
          };Node *current;           //current process placement in queue
};


#endif // CSCI_311_SCHEDULER_He
