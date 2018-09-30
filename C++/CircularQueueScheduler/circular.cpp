/**
 * @file circular.cpp
 *
 * @brief
 *    A circular queue for processes implemented with a doubly linked list.
 *
 * @author Jacob W
 * @date 2/10/18
 */

#include "circular.h"
#include "process.h"
/**
 * @brief   Node constructor.
 */
CircularQueue::Node::Node()
{
  //next=nullptr;
  //prev=nullptr;
  //data=new Process(p);
}

/**
 * @brief   Node constructor.
 * @param   p A reference to a Process to be stored in this Node.
 */
CircularQueue::Node::Node(const Process& p)
{
  next=nullptr;
  prev=nullptr;
  data=new Process(p);
}

/**
 * @brief   Node destructor.
 */
CircularQueue::Node::~Node()
{
  delete data;
  data = nullptr;
}

/**
 * @brief   CircularQueue constructor.
 */
CircularQueue::CircularQueue()
{
  current = nullptr;
}

/**
 * @brief   CircularQueue destructor.
 */
CircularQueue::~CircularQueue()
{
  delete current;
  current=nullptr;
}

/**
 * @brief   Appends a new Node at the end of the CircularQueue.
 * @param   p A reference to a Process to be stored in the new Node.
 * @return  Nothing.
 *
 * Creates a new Node to hold the data and appends the Node at the end
 * of the queue. The end of the queue is accessed through current->prev.
 */

 //IS THIS THE MEMORY LEAK???

void CircularQueue::append(const Process& p)
{
  if (current == nullptr){ //if queue is empty
    Node *temp = new Node(p);
    current = temp;
    current->next = current;
    current->prev = current;
   }//if
   else if (current == current->prev){//if queue has 1 node
    Node *temp = new Node(p);
    current->prev=temp;
    current->next=temp;
    temp->prev = current;
    temp->next=current;
   }
   else{ //if queue has 1+ nodes
    Node *temp = new Node(p);
    temp->prev = current->prev;
    temp->next = current;
    current->prev->next = temp;
    current->prev = temp;
  }
}//append




/**
 * @brief   Get the current Process.
 * @return  A pointer to the Process stored in the current Node in the queue,
 *          or nullptr if the queue is empty.
 */

Process* CircularQueue::getCurrent()
{
  if(current != nullptr){
    return current->data;
  }//if
  else{
    return nullptr;
  }//else
}

/**
 * @brief   Get the next Process in the queue.
 * @return  A pointer to the data stored in the next Node in the queue,
 *          or nullptr if the queue is empty.
 *
 * Checks to see if the current Process has completed and remove it if so.
 * If the queue is not empty, the current pointer is advanced to the next Node.
 */

//MEMORY LEAK?????????????????????????????????????????????????
// WHERE ARE YOU
Process* CircularQueue::getNext()
{
  //this checks to make sure the queue isnt empty and that current isnt the
  // only node there. If current is only node we set to nullptr and return
  if (current != nullptr && current->prev != current){
    if(current->data->done() == false){ //if proccess is completed
      Node *temp = current;
      current = current->next;
      current->prev = temp->prev;
      current->prev->next = current;
      delete temp;
      //temp=nullptr; MEMORY LEAK??
    }
  else{ // process not finished so we progress current
      current=current->next;
    }
  return current->data;
}//main if
  else if ( current == current->prev){ // if current is only one in the queue
    current=nullptr;
    return nullptr;
    }
  else{//top if statement and means queue is empty
    return nullptr;
  }
}//getNext
