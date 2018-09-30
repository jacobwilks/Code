/**
 * @file process.h   Declaration of a Process class.
 *
 * @brief
 *  Creates the necessary functions and variables for the scheduler to run
 *  according to the assignment
 *
 * @author Jacob Wilks
 * @date 2/10/18
 */

 #ifndef CSCI_311_PROCESS_H
 #define CSCI_311_PROCESS_H

 #include <string>

using std::string;

// #include "circular.h"
//#include "process.h"

 class Process {
     public:
       Process(); //constructors
       Process(int pid, string execute, int arrive, int burst, int used);
       ~Process();  //deconstructor
       bool done(); //checks if process is complete
       void incTimeUsed(); //increments timeUsed if process not complete
       void printCompleted(int now);//print finished process once fully done
     private:
       int burstTime; //amount of time it takes for process to run and finish
       int timeUsed; //Amount of time that it took for the process to run
       int pid;      //processID
       int arrivalTime; //time of clock cycle that process is queued
       std::string executable;  //executable path name
 };

 #endif // CSCI_311_SCHEDULER_H
