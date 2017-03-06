// Source for Problem 1

#include "p1.h"

/*
StudentRecord::StudentRecord( std::string lastname, std::string firstname, float score) { 
  lastname_ = lastname;
  firstname_ = firstname;
  score_ = score;
};

StudentRecord::~StudentRecord(){};

bool StudentRecord::input( std::istream & in ) {   
    std::string line;   
    std::getline( in, line, ',');   
    lastname_ = line;   
    std::getline( in, line, ',');   
    firstname_ = line;   
    std::getline( in, line );   
    score_ = std::atof( line.c_str() );   
    if ( line == "")      
       return false;   
    else     
       return true; 
};



 StudentRecord StudentRecord::calculate_average(/*StudentRecord * p) {

  std::cout << "Magic" << std::endl;

};
*/


StudentRecord::StudentRecord( std::string lastname, std::string firstname, float score) { 
  lastname_ = lastname;
  firstname_ = firstname;
  score_ = score;
};

StudentRecord::~StudentRecord(){};

bool StudentRecord::input( std::istream & in ) {   
    std::string line;   
    std::getline( in, line, ',');   
    lastname_ = line;   
    std::getline( in, line, ',');   
    firstname_ = line;   
    std::getline( in, line );   
    score_ = std::atof( line.c_str() );   
    if ( line == "") {     
       return false; 
    }  
    else {
       return true; 
    }
};

/*

StudentRecord StudentRecord::calculate_average(std::vector<StudentRecord> * p) {
  float average = 0.;
  std::cout << "Magic" << std::endl;

};
*/
