/**
 * @file hash.cpp
 *
 * @brief
 *    Implementation of a hash table. Implements multiple functions that
 *    affect the table in various ways. Statistics are kept throughout the
 *    running of the program and are printed at the end.
 *
 * Websites that were referenced:
 * http://www.cplusplus.com/reference/list/list/
 * http://www.cplusplus.com/reference/fstream/ifstream/
 * http://www.cplusplus.com/reference/list/list/empty/
 *
 * @author Jacob W
 * @date 3/10/18
 */

#include <stdio.h>
#include <fstream>
#include "hash.h"
#include <string>
#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

/**
 * @brief   Constructor - used for keeping statistics about table
 * @return  Nothing.
 *
 * Initializes and holds the values that are used to create statistics.
 */
Hash::Hash(){
  collisions=0;                  // total number of collisions
  longestList=0;                 // longest list ever generated
  runningAvgListLength=0;        // running average of average list length
}

/**
 * @brief   Removes an entry from hash table if it exists
 * @param  word - value that we plan to search for then remove from vector
 * @return  Nothing.
 *
 * Searches through the hash table; if the string is found it will remove it
 * and recalculate the statistics.
 */
void Hash::remove(string word){
  list<string>::iterator it;
  for (int i=0; i< HASH_TABLE_SIZE; i++){
    for (it=hashTable[i].begin(); it != hashTable[i].end(); it++){
      if (word == *it){
        hashTable[i].remove(*it);
        avg();
        return;
      }
    }
  }
}

/**
 * @brief   Displays the entire hash table
 * @return Nothing
 *
 * Iterates through the table displaying the value as it finds them and going
 * until the entire table is printed.
 */
void Hash::print(){ //do i need to check for empty hash table?
  list<string>::iterator it;
  for (int i=0; i< HASH_TABLE_SIZE; i++){
    cout<<i<<":"<<'\t';
    for (it=hashTable[i].begin(); it != hashTable[i].end(); it++){
      cout << *it<<", ";
    }
    cout<<endl;
  }
}

/**
 * @brief   Reads in values from input file and saves them in hash table
 * @param   filename Name of file to open and begin reading from
 * @return  Nothing.
 *
 * Creates a new input stream file and sets it to the filename variable.
 * Then while bringing in new values it checks to see if there was a collision,
 * checks to see if the longest list needs to be updated, then once those are
 * done it calculates the average statistics and then closes the input stream.
 */
void Hash::processFile(string filename){
  ifstream ifs;
  ifs.open(filename);
  if (!ifs.eof()){
    string temp;
    unsigned int listsize;
    while(getline(ifs,temp)){
      int value = hf(temp);
      hashTable[value].push_back(temp);
      if (hashTable[value].size() > 1){ // non empty list
        collisions++;
      }
      listsize = hashTable[value].size();
      if (listsize > longestList){
        longestList = listsize;
      }
      avg();
    }
    ifs.close();
  }
}

/**
 * @brief   Searches hash table for a specific value
 * @param   word Value that we are looking for inside table
 * @return found True if the value was found false if not
 * Iterates through the table searching for a value. Sets found to true
 * when the value is found and stays as false if not found in table.
 */
bool Hash::search(string word){
  int value = hf(word);
  bool found = false;
  list<string>::iterator it;
  for (it=hashTable[value].begin(); it != hashTable[value].end(); it++){
    if (word == *it){
      found = true;
      return found;
    }
  }
  return found;
}

/**
 * @brief   Outputs the hash table to a new file.
 * @param   filename Name of file to output hashtable to.
 *
 * Outputs the hash table to the specified file name. It prints it to this
 * file in the exact same format as the print function above.
 */
void Hash::output(string filename){
  ofstream ofs;
  ofs.open(filename);
  list<string>::iterator it;
  for (int i=0; i< HASH_TABLE_SIZE; i++){
    ofs<<i<<":"<<'\t';
    for (it=hashTable[i].begin(); it != hashTable[i].end(); it++){
      ofs << *it<<", ";
    }
    ofs<<endl;
  }
  ofs.close();
}

/**
 * @brief   Prints out statistics regarding hash table
 * @return  Nothing.
 *
 * Uses statisics that are updated throughout the program running and prints
 * them out. Collisions is how many times a number was inserted into a spot with
 * another entry already. LongestList keeps track of the list with the most
 * collisions. AverageListLength keeps track every time a list is updated with
 * an average calculation of all list lengths. Load factor calculates the
 * entries occupied in the table with the total number of buckets in the table.
 */
void Hash::printStats(){
  cout<<"Total Collisions = "<<collisions<<endl;
  cout<<"Longest List Ever = "<<longestList<<endl;
  cout<<"Average List Length Over Time = "<<runningAvgListLength<<endl;
  cout<<"Load Factor = "<<calcLoadF()<<endl;
}

/**
 * @brief   Helper function to calculate the load factor of the table
 * @return  loadFactor  The total load factor of the hash table.
 */
double Hash::calcLoadF(){
  double loadFactor=0.0;
  double runningcount=0.0;
  for (int i=0; i< HASH_TABLE_SIZE; i++){
    runningcount=runningcount+hashTable[i].size();
  }
  loadFactor = runningcount / HASH_TABLE_SIZE;
  return loadFactor;
}

/**
 * @brief   Helper function to calculate the average list length of the table
 * @return  Nothing
 *
 * This is called every time the list is updated (Removal or Entry) in order to
 * keep a running statistic that is constantly updated.
 */
void Hash::avg(){
  int cursize=0;
  double curListLength=0.0;
  double runningcount=0.0;
  for (int i=0; i< HASH_TABLE_SIZE; i++){
    runningcount=runningcount+hashTable[i].size();//# of items in hash table
    if (!hashTable[i].empty()){
      cursize++; //Number of non empty lists.
    }
  }
  curListLength = runningcount / cursize;
  runningAvgListLength = (curListLength + runningAvgListLength)/2.0;
}
