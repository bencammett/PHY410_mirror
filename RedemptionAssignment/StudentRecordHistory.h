#ifndef STUDENTRECORDHISTORY_H
#define STUDENTRECORDHISTORY_H


#include "StudentRecord.h"


class StudentRecordHistory: public StudentRecord {

 public:
    StudentRecordHistory(){};
    ~StudentRecordHistory(){};

    virtual void print( std::ostream & out = std::cout ) const {
        out << "\t" << lastname_ << "," << firstname_ << "," << score() << std::endl;
  }

    virtual bool input( std::istream & in ) {
    // Names
    std::string line;
    std::getline( in, line, ',');
    lastname_ = line;
    std::getline( in, line, ',');
    firstname_ = line;
    // Scores with weights, higher vs lower
    std::getline( in, line, ',' );
    double score1 = std::atof( line.c_str() );
    std::getline( in, line );
    double score2 = std::atof( line.c_str() );    
    if ( score1 > score2 ) {
      student_scores_.push_back( score1 ); weighted_.push_back( 0.6 );
      student_scores_.push_back( score2 ); weighted_.push_back( 0.4 );
    } else {
      student_scores_.push_back( score2 ); weighted_.push_back( 0.6 );
      student_scores_.push_back( score1 ); weighted_.push_back( 0.4 );
    }
    if ( line == "") 
      return false;
    else {
      compute_score_();
      return true;
    }
  }
};

#endif


