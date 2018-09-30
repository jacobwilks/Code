/**
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger && Jacob Wilks
 * @date 2/22/18
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage
//
// You may add your private helper functions here!
//

   void mSort(int,int,int); //helper function that calls itself and merge
   void merge(int,int,int,int); //sorts and merges two sorted vectors together
   void qSort(int,int,int); //helper function that calls itself and partition
   int partition(int,int,int); //given a pivot splits vector into two and sorts
   bool isSmaller(Record*, Record*); // this is one I used - you may delete
   int random(int,int); //creates a random pivot point for quick sort
   int randomizedPartition(int,int,int); //uses the random pivot then returns a
   //call to partition that will finish sorting based off the new pivot
};

#endif // CSCI_311_CENSUSDATA_H
