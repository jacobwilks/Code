/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 *
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger && Jacob Wilks
 * @date 2/22/18
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"
#include <cmath>
#include <random>
#include <chrono>

/**
 * @brief   Uses Insertion Sort on passed in vector of data
 * @param   Type - determines if sorting by name or population
 */
void CensusData::insertionSort(int type) {
  int ds = data.size(); //to avoid a comparison issue
  if (type==0){
    for (int i = 1; i < ds; i++){
      Record* temp = data[i];
      int j = i-1;
      while ( j >= 0 && (data[j]->population > temp->population)){
        data[j+1] = data[j];
        j = j - 1;
      }
      data[j+1] = temp;
    }
  }
  else{
    for (int i = 1; i < ds; i++){
      Record* temp = data[i];
      int j = i-1;
      while ( j >= 0 && (isSmaller(temp,data[j]))){
        data[j+1] = data[j];
        j = j - 1;
      }
      data[j+1] = temp;
      }
  }//else
}

/**
 * @brief   Calls helper function that actually does the sorting
 * @param   Type - determines if sorting by name or POPULATION
 */
void CensusData::quickSort(int type) {
  qSort(type,0,data.size()-1);
}

/**
 * @brief   Recursively calls quicksort after getting a randomized pivot point
 * @param   Type - determines if sorting by name or POPULATION
 * @param   p - beginning of vector, r - end of vector
 */
void CensusData::qSort(int type, int p, int r){
  if ( p < r){
    int q = randomizedPartition(type,p,r);
    qSort(type,p,q-1);
    qSort(type,q+1,r);
  }
}
/**
 * @brief   Splits data into two smaller arrays and recursively sorts each
 * @param   Type - determines if sorting by name or POPULATION
 * @param   p - beginning of vector, r - end of vector
 * @return   last spot of vector
 */
int CensusData::partition(int type, int p, int r) {
  Record* temp; //use this to hold data when exchanging
  if (type == 0){
    int i = p -1;
    for ( int j = p; j < r; j++){
      if (data[j]->population <= data[r]->population){
        i = i+1;
        temp = data[i]; //we swap data[i] and data[j]
        data[i] = data[j];
        data[j] = temp;
     }
    }
    temp = data[i+1]; //we swap data[i] and data[r]
    data[i+1] = data[r];
    data[r] = temp;
    return i+1;
  }
  if (type == 1){
    int i = p -1;
    for ( int j = p; j < r; j++){
      if (isSmaller(data[j],data[r])){
        i = i+1;
        temp = data[i];//we swap data[i] and data[j]
        data[i] = data[j];
        data[j] = temp;
      }
    }
    temp = data[i+1];//we swap data[i] and data[r]
    data[i+1] = data[r];
    data[r] = temp;
    return i+1;
  }
  return r;
}

/**
 * @brief   Calls helper function that actually does the sorting
 * @param   Type - determines if sorting by name or POPULATION
 */
void CensusData::mergeSort(int type) {
  mSort(type,0,data.size()-1);
}

/**
 * @brief   Creates two vectors by splitting original data in half and sorting
 * @brief   each half before merging them back together at the end
 * @param   Type - determines if sorting by name or POPULATION
 */
void CensusData::merge(int type, int p, int q, int r) {
  unsigned int n1=q-p+1;
  unsigned int n2=r-q;
  unsigned int j,i,k,ls,rs;
  vector<Record*>lhs,rhs;
  //fill lhs vector
  for ( i = 1; i <= n1; i++){
    lhs.push_back(data[p+i-1]);
  }
  //fill rhs vector
  for ( j=1; j <= n2; j++){
    rhs.push_back(data[q+j]);
  }
  ls=lhs.size(); //these are for ease of reading in the for loops later on
  rs=rhs.size();
  i=0;
  j=0;
  k=p;
  if (type==0){
    for (; i<ls && j<rs;){
      int temp, temp1;
      temp = (lhs[i]->population);
      temp1=(rhs[j]->population);
        if(temp <= temp1){
          data[k]=lhs[i];
          k=k+1;
          i=i+1;
        }
        else{
          data[k]=rhs[j];
          k=k+1;
          j=j+1;
        }
    }
  }//if
  else{//this is saying type =1
    for (; i<ls && j<rs;){
      if(isSmaller(lhs[i],rhs[j])){
        data[k]=lhs[i];
        k=k+1;
        i=i+1;
      }
      else{
        data[k]=rhs[j];
        k=k+1;
        j=j+1;
      }
    }
  }
  //these are to continue adding leftover items
  for (;i<ls;){
    data[k]=lhs[i];
    k=k+1;
    i=i+1;
   }
  for (;j<rs;){
    data[k] = rhs[j];
    k=k+1;
    j=j+1;
   }
}//end of function

/**
 * @brief   Recursively calls merge sort and continues to pass in different
 * @brief   values to sort each side of the array until each side is sorted
 * @brief   then will merge the two sorted sides together to get final product
 * @param   Type - determines if sorting by name or POPULATION
 * @param   p - beginning of vector, r - end of vector
 */
void CensusData::mSort(int type,int p, int r){
  if(p<r){
    int q = floor(p+r)/2;
    mSort(type, p,q);
    mSort(type,q+1,r);
    merge(type,p,q,r);
  }
}
/**
 * @brief   Checks if a given string is smaller value than another given string
 * @param   A - first record passed in. B - second record passed in.
 * @return true if first string is equal or smaller than second string
 * @return false if string is larger
 */
bool CensusData::isSmaller(Record* a, Record* b){
  string left = *a->city;
  string right = *b->city;
  if(left.compare(right) <= 0){ //if its the same or smaller
    return true;
  }
  else{ // if second string is bigger
    return false;
  }
}
/**
 * @brief   Creates a random number for us to use as a pivot
 * @param   p - beginning of vector, r - end of vector
 * @return  random number to be used as pivot
 */
int CensusData::random(int p, int r){
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  std::uniform_int_distribution<int>distribution(p,r);
  return distribution(generator);
}

/**
 * @brief   Calls random function to create a random pivot and calls partition
 * @brief   with the new randomized value as its pivot
 * @param   Type - determines if sorting by name or POPULATION
 * @param   p - beginning of vector, r - end of vector
 * @return a call to function partition with a random pivot being passed in
 */
int CensusData::randomizedPartition(int type,int p, int r){
  int i = random(p,r);
  Record *temp = data[r];
  data[r] = data[i];
  data[r]=temp;
  return partition(type,p,r);
}
