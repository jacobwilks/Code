/**
 * @file rbtree.cpp

 * @brief Implementation of a Red Black Tree's functions that build, delete,
 *   search, find, and adjust the tree according the red black tree properties
 *   to ensure that we have properly built and maintain a red black tree.
 *   This file contains all necessary functions besides the input processing.
 *
 * CLRS Sudo Code was heavily used throughout this program and is stated where.

 * @author Jacob Wilks
 * @date 4/20/18
 **/
#include <iostream>
#include <iomanip>
#include "rbtree.h"
#include "rbapp.h"

using std::cout;
using std::setw;
using std::endl;
//constructors

/**
 * @brief  Constructor for RBTree Class where nil is instantiated
 * @return  Nothing.

 * The nil node is created and root is set to the brand new nil node.

*/
RBTree::RBTree(){
  nil = new Node();
  root = nil;
}

/**
 * @brief  Constructor for RBTree's private Node Class
 * @return  Nothing.

 * Right,left,parent are all instantiated to NULL and color is set to Black

*/
RBTree::Node::Node(){
  right = NULL;
  left = NULL;
  parent = NULL;
  color = 'B';
}

/**
 * @brief  Constructor for RBTree Class where nil is instantiated
 * @param key - Const string passed by reference which holds the key
 * @param value - Const string passed by refernence which holds satellite data
 * @return  Nothing.

 * Key and value are created and stored. Right,left,parent are set to NULL and
 * the color is set to red

*/
RBTree::Node::Node(const string& key, const string& value){
  this->key = new string(key);
  this->value = new string(value);
  right = NULL;
  left = NULL;
  parent = NULL;
  color = 'R';
}

//deconstuctors

/**
 * @brief  DeConstructor for RBTree Class where nil is instantiated
 * @return  Nothing.

 nil is deleted
*/
RBTree::~RBTree(){
  delete nil;
}

/**
 * @brief  DeConstructor for RBTree's private node class
 * @return  Nothing.
 *
*/
RBTree::Node::~Node(){
}

// private accessors - must all use nil
/**
 * @brief  Finds Successor to passed in Node 't'. Based off CLRS Suedo Code
 * @param t = Node that is passed in in order to search for its successor
 * @return  Node 'y' which is successor to passed in Node 't'

 * Takes in passed in node and finds the successor to the node and returns it
*/
RBTree::Node* RBTree::rbTreeSuccessor(Node* t){
  Node* y=t->parent;
  if (t->right != nil){
    return rbTreeMinimum(t->right);
  }
  while(y!= nil && (t == y->right)){
    t  = y;
    y = y->parent;
  }
  return y;
}

/**
 * @brief  Finds predecessor to passed in Node 't' Based off CLRS Suedo Code
 * @param t = Node that is passed in in order to search for its predeccessor
 * @return  Node 'y' which is predeccessor to passed in Node 't'

 * Takes in passed in node and find the predeccessor to the node and returns it

*/
RBTree::Node* RBTree::rbTreePredecessor(Node* t){
  Node* y=t->parent;
  if (t->left != nil){
    return rbTreeMaximum(t->left);
  }
  while(y!= nil && (t == y->left)){
    t  = y;
    y = y->parent;
  }
  return y;
}

/**
 * @brief  Finds minimum node where t is root in the search.
 .         Based off CLRS Suedo Code
 * @param t = Node that is passed in in order to search for its minimum
 * @return  Node 't' which is now set to the minimum of original t node

 * Uses the passed in node 't' as root and finds the minimum node in that
 * subtree.

*/
RBTree::Node* RBTree::rbTreeMinimum(Node* t){
  while (t->left != nil){
    t = t->left;
  }
  return t;
}

/**
 * @brief  Finds maximum node where t is root in the search
 *          Based off CLRS Suedo Code
 * @param t = Node that is passed in in order to search for its maximum
 * @return  Node 't' which is now set to the maximum  of original t node

 * Uses the passed in node 't' as root and finds the maximum node in that
 * subtree.

*/
RBTree::Node* RBTree::rbTreeMaximum(Node* t){
  while (t->right != nil){
    t = t->right;
  }
  return t;
}

/**
 * @brief  Creates and inserts a new Node
 * @param key - New node's key value
 * @param value - New node's satellite data
 * @return  Nothing.
*/

void RBTree::rbInsert(const string& key, const string& value){
  Node* temp = new Node(key,value);
  rbInsert(temp); //inserts new node into RBTree
}

/**
 * @brief  rbInsert based off CLRS Suedo Code
 * @param t = Node that is passed in that needs to be inserted into the tree
 * @return  Nothing.

 * Goes through the tree using the RB Tree properties as a guideline and
 * inserts the new node into its proper place. This may break the tree
 * guidelines but rbInsertFixup is called at the end to correct it.
*/
void RBTree::rbInsert(Node* t){
  Node* y = nil;
  Node* x = root;
  while (x != nil){
    y = x;
    if ( *(t->key) < *(x->key)){
      x = x->left;
    }
    else{
      x = x->right;
    }
  }
  t->parent = y;
  if ( y == nil){
    root = t;
  }
  else if (*(t->key) < *(y->key)){
    y->left = t;
  }
  else{
    y->right = t;
  }
  t->left = nil;
  t->right = nil;
  t->color = 'R';
  rbInsertFixup(t);
}

/**
 * @brief  rbInsertFixup based off CLRS Suedo Code
 * @param t = Node that is passed in that needs to be inserted into the tree
 * @return  Nothing.

 * Ensures that the RB Properies are still in place once a new node is
 * inserted into the tree.
*/
void RBTree::rbInsertFixup(Node* t){
  Node* y;
  while (t->parent->color == 'R'){
    if (t->parent == t->parent->parent->left){
      y = t->parent->parent->right;
      if (y->color == 'R'){
        t->parent->color = 'B';
        y->color = 'B';
        t->parent->parent->color = 'R';
        t = t->parent->parent;
      }
      else if(t == t->parent->right){
        t = t->parent;
        leftRotate(t);
      }
      else{
        t->parent->color = 'B';
        t->parent->parent->color = 'R';
        rightRotate(t->parent->parent);
      }
    }
    else{
      y = t->parent->parent->left;
      if (y->color == 'R'){
        t->parent->color = 'B';
        y->color = 'B';
        t->parent->parent->color = 'R';
        t = t->parent->parent;
      }
      else if (t == t->parent->left){
        t = t->parent;
        rightRotate(t);
      }
      else{
        t->parent->color = 'B';
        t->parent->parent->color = 'R';
        leftRotate(t->parent->parent);
      }
    }//second else
  }//while
  root->color='B';
}//end of function


// private mutators minus fixups

/**
 * @brief  leftRotate based off CLRS Suedo Code
 * @param t = Node that is passed in that needs to be adjusted
 * @return  Nothing.
*/
void RBTree::leftRotate(Node* t){
  Node* y = t->right;
  t->right = y->left;
  if (y->left != nil){
    y->left->parent = t;
  }
  y->parent = t->parent;
  if (t->parent == nil){
    root = y;
  }
  else if ( t == t->parent->left){
    t->parent->left = y;
  }
  else{
    t->parent->right = y;
  }
  y->left = t;
  t->parent = y;
}

/**
 * @brief  rightRotate based off CLRS Suedo Code
 * @param t = Node that is passed in that needs to be adjusted
 * @return  Nothing.
*/
void RBTree::rightRotate(Node* t){
  Node* y = t->left;
  t->left = y->right;
  if (y->right != nil){
    y->right->parent = t;
  }
  y->parent = t->parent;
  if (t->parent == nil){
    root = y;
  }
  else if ( t == t->parent->right){
    t->parent->right = y;
  }
  else{
    t->parent->left = y;
  }
  y->right = t;
  t->parent = y;
}

/**
 * @brief  rbTransplant based off CLRS Suedo Code
 * @param u = Passed in node that is used to determine how to fix tree.
 * @param v =  Passed in Node that needs to be moved and adjusted in order to
 *             hold properies of RB tree.
 * @return  Nothing.
*/
void RBTree::rbTransplant(Node* u, Node* v){
  if (u->parent == nil){
    root = v;
  }
  else if (u == u->parent->left){
    u->parent->left = v;
  }
  else{
    u->parent->right = v;
  }
  v->parent = u->parent;
}



//prints
/**
 * @brief  Prints tree in Reverse Order
 * @param x = Node that you pass in which is where the search is started.
 * @return  Nothing.
*/
void RBTree::reverseInOrderPrint(Node *x, int depth) {
  if ( x != nil ) {
    reverseInOrderPrint(x->right, depth+1);
    cout << setw(depth*4+4) << x->color << " ";
    cout << *(x->key) << " " << *(x->value) << endl;
    reverseInOrderPrint(x->left, depth+1);
  }
}

/**
 * @brief  Helper Function that calls reverseInOrderPrint
 * @return  returns if tree is empty
 * As long as tree is not empty it will print it based off root and zero depth
*/
void RBTree::rbPrintTree(){
  if (root != nil){
    reverseInOrderPrint(root,0); //prints tree from root
  }
  else{
    return;
  }
}


//searches

/**
 * @brief  rbTreeSearch based off CLRS Suedo Code
 * @param t = Node you want to search.
 * @param key = Node's key that you are searching for.
 * @return  Either a call to rbTreeSearch on t->left or right depending if the
 * node's key is greater or smaller than the passed in value.
*/
RBTree::Node* RBTree::rbTreeSearch(Node* t, const string& key){
  if ( (t == nil)|| (key == *(t->key))){
    return t;
  }
  if (key < *(t->key)){ //go to left subtree
    return rbTreeSearch(t->left,key);
  }
  else{ //right subtree
    return rbTreeSearch(t->right,key);
  }
}

/**
 * @brief  Finds all Matching occurences of a Node
 * @param key = Key that we are trying to find inside RBT
 * @return  matchingNodes = vector of string pointers to all nodes that matched
 * the passed in key value with the node's value.

 This program works in three steps, first it finds the initial value that it
 was told to look for. Then it checks the predecessor and ensures nothing is
 in the right subtree that also matches value. Then it checks successor to
 ensure nothing is in the left subtree that matches the value.
*/
vector<const string*> RBTree::rbFind(const string& key){
  vector <const string*> matchingNodes; //matched nodes are inserted here
  Node* temp = nil;
  Node* pre= nil; //predecessor
  Node* suc= nil; //successor
  temp = rbTreeSearch(root,key);
  // if the key matches, push to new vector
  if (temp != nil && *(temp->key) == key){
    matchingNodes.push_back(temp->value);

    // first match is now found and we use predecessor to check leftmost node
    // in the right subtree to confirm no more matches

    pre = rbTreePredecessor(temp);
    while (pre != nil && *(pre->key) == key){
      matchingNodes.push_back(pre->value);
      pre = rbTreePredecessor(pre);
    }

    //uses successor to confirm there are no more matches to the search inside
    // the rightmode node of left subtree.
    suc = rbTreeSuccessor(temp);
    while (suc != nil && *(suc->key) == key){
      matchingNodes.push_back(suc->value);
      suc = rbTreeSuccessor(suc);
    }
  }//if statement
  return matchingNodes; //return vector of string pointers
}


//deletes
/**
 * @brief  Deletes the node with a matching key and value that was passed in
 * @param key = Key that we are trying to find inside RBT
 * @param value = satellite data that we are trying to find inside RBT
 * @return  Nothing.

 This functions similar to rbFind, however instead of it deleting as it goes
 like it previously did, it now adds all matching nodes into a new vector
 then once it has gone through the entire tree comparing it then goes
 through the new vector deleting each item. The way I previously had it was
 a problem because I was deleting as I went causing the while loops to exit
 incorectly.
*/
void RBTree::rbDelete(const string& key, const string& value){
  Node* x = nil;
  Node* pre; //predecessor
  vector <Node*> matches;
  Node* temp;
  x = rbTreeSearch(root,key);
  if (x == nil){
    return;
  }
  //pushes first entry and uses successor to look for more
  temp = x;
  while((temp != nil) && (*temp->key) == key){
    matches.push_back(temp);
    temp = rbTreeSuccessor(temp);
  }//if
  //uses predecessor to look for more
  pre = rbTreePredecessor(x);
  while (pre != nil && (*pre->key) == key){
    matches.push_back(pre);
    pre = rbTreePredecessor(pre);
  }
  //iterates through the vector that was filled with all matching keys
  // and calls rbDelete on them to get rid of them all.
  for ( vector<Node*>::iterator it = matches.begin();
  it!= matches.end(); it++){
    if (*(*it)->value == value){
      rbDelete(*it);
    }
  }
}//end of function

/**
 * @brief  rbDeleteFixup based off CLRS Suedo Code
 * @param t = Node that is passed in that needs to be deleted from the tree
 * @return  Nothing.

 * Ensures that the RB Properies are still in place once a new node is
 * deleted from the tree.
*/
void RBTree::rbDeleteFixup(Node* t){
  Node* w = t;
  while(t != root && t->color == 'B'){
    if ( t == t->parent->left){
      w = t->parent->right;
      if (w->color == 'R'){
        w->color = 'B';
        t->parent->color = 'R';
        leftRotate(t->parent);
        w = t->parent->right;
      }
      if (w->left->color == 'B' && w->right->color == 'B'){
        w->color = 'R';
        t = t->parent;
      }
      else{
        if (w->right->color == 'B'){
          w->left->color = 'B';
          w->color = 'R';
          rightRotate(w);
          w = t->parent->right;
        }
        w->color = t->parent->color;
        t->parent->color = 'B';
        w->right->color = 'B';
        leftRotate(t->parent);
        t = root;
      }
    }
    else{
      w = t->parent->left;
      if (w->color == 'R'){
        w->color = 'B';
        t->parent->color = 'R';
        rightRotate(t->parent);
        w = t->parent->left;
      }
      if (w->right->color == 'B' && w->left->color == 'B'){
        w->color = 'R';
        t = t->parent;
      }
      else{
        if (w->left->color == 'B'){
          w->right->color = 'B';
          w->color = 'R';
          leftRotate(w);
          w = t->parent->left;
        }
        w->color = t->parent->color;
        t->parent->color = 'B';
        w->left->color = 'B';
        rightRotate(t->parent);
        t = root;
      }//else right above
    }//large else block
  }//while
  t->color = 'B';
}//end of function

/**
 * @brief  rbInsert based off CLRS Suedo Code
 * @param t = Node that is passed in that needs to be inserted into the tree
 * @return  Nothing.

 * Goes through the tree using the RB Tree properties as a guideline and
 * deletes given node from the tree. This may break the tree
 * guidelines however it calls a function to correct it as it runs. For
 * example calls rbTransplant if it goes into the conditional if statement of
 * if (t->left == nil).

*/
void RBTree::rbDelete(Node*t){
  Node* y = t;
  Node* x = t;
  char ogColor = y->color;

  if (t->left == nil){
    x = t->right;
    rbTransplant(t,t->right);
  }
  else if (t->right == nil){
    x = t->left;
    rbTransplant(t,t->left);
  }
  else{
    y= rbTreeMaximum(t->left);
    ogColor = y->color;
    x = y->left;
    if(y->parent == t){
      x->parent = y;
    }
    else{
      rbTransplant(y,y->left);
      y->left = t->left;
      y->left->parent = y;
    }
    rbTransplant(t,y);
    y->right = t->right;
    y->right->parent = y;
    y->color = t->color;
  }
  if (ogColor == 'B'){
    rbDeleteFixup(x);
  }
}
