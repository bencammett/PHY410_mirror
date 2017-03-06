// Header for Problem 1


#ifndef StudentRecord_h
#define StudentRecord_h


#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>

/*
class StudentRecord {
 public:

  StudentRecord( std::string lastname, std::string firstname, float score);
  ~StudentRecord();
 
  bool input( std::istream & in );

  StudentRecord calculate_average(/*StudentRecord * p);



 private:
  std::string lastname_;
  std::string firstname_;
  float score_;


};
*/

class StudentRecord {
 public:

  StudentRecord( std::string lastname, std::string firstname, float score);
  ~StudentRecord();
 
  bool input( std::istream & in );

  //  StudentRecord calculate_average(std::vector<StudentRecord> * p);
  //might need to change this type


 private:
  std::string lastname_;
  std::string firstname_;
  float score_;


};



#endif
