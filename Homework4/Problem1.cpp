// Main for Problem 1

#include <iostream>
#include <vector>
#include "p1.h"
/*
int main(int argc, char ** argv ){

  //StudentRecord SR;
  std::vector<StudentRecord> StudentRecords;
  // StudentRecords.push_back(SR);
  // StudentRecord * pr = &StudentRecords;



  std::cout << "Vector Size: " << StudentRecords.size() << std::endl;

  std::cout << "File: " << argv[1] << std::endl;


  std::cout << "Test Output: Gambino" << std::endl;



  return 0;
}

  // needs to take file name from command line
  // open said file
  // needs to store in vector
  // needs to calculate average: pass by pointer to vec to fcn, fcn: cal_avg
  // DO NOT pass by value
  // run like: ./average records.txt
*/

void calculate_average(std::vector<StudentRecord> * p);


int main(int argc, char ** argv ){

  //StudentRecord SR;
  std::vector<StudentRecord> StudentRecords;
  // StudentRecords.push_back(SR);
  // StudentRecord * pr = &StudentRecords;
  //StudentRecords * p = &StudentRecords;
  // StudentRecord SR;
  // StudentRecords.push_back(SR);



  std::cout << "Vector Size: " << StudentRecords.size() << std::endl;

  calculate_average( &StudentRecords);

  std::cout << "File: " << argv[1] << std::endl;


  std::cout << "Test Output: Gambino" << std::endl;



  return 0;
}


void calculate_average(std::vector<StudentRecord> * p) {
  float average = 0.;

  std::cout << "Testing vector input." << std::endl;

};
