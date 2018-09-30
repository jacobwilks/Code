/* This assignment originated at UC Riverside.*/
/**
 * @file hash_function.cpp
 *
 * @brief
 *    The hash function that was used to encode my hash table
 *
 * Websites that were referenced:
 * http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
 *
 * @author Jacob W
 * @date 3/10/18
 */
#include <string>
#include "hash.h"

using std::string;
/*
I decided to combine the rotating hash and the modified bernstein into an
addition equation based off the formulas that I found on this website.
//http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
I put them together and added them with okay results, but decided to start
changing the numbers with the shift amounts and the initial hash value. I found
many different hash values that worked with my equation, however, 5127
performed far better than any other number I could try. I ended back on the 33
that bernstein used and slightly modifying their respective formulas each as I
continued to search for the best results. left bit shift and right bit shift
ended up affecting the quality of the hash function greatly and after much
testing I ended on the numbers of 2 and 6. Finally, I added +ins[i] to the end
of the rotating hash equation and it helped reduce the collisions and longest
list amount by a good amount. I attempted to add random formulas to the final
hash product such as hash += (hash << 3) and hash ^= (hash>> 11) but completely
ruined the table and I removed it. After a long time of changing the formula's
numbers and trying random additions, subtractions and xors I decided that this
was the best function I could make. I compared it to each of the functions it
was derived from and appeard to perform as well or even slightly better on our
list of word sets.Below is the final product of my hash function.
*/
int
Hash::hf ( string ins ) {
  int hash = 5127;
  for (unsigned int i=0; i < ins.length(); i++){
    hash ^= (33 * (hash) ^ ins[i])+((hash << 2) ^ (hash >>6) ^ ins[i])+ins[i];
  }
  return hash % HASH_TABLE_SIZE;
}
