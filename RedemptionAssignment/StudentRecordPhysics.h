#ifndef STUDENTRECORDPHYSICS_H
#define STUDENTRECORDPHYSICS_H


#include "StudentRecord.h"


class StudentRecordPhysics: public StudentRecord {

 public:
    StudentRecordPhysics(){};
    ~StudentRecordPhysics(){};

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
        // Scores with weights
        std::getline( in, line, ',' );
        student_scores_.push_back( std::atof( line.c_str() ) );
        weighted_.push_back( 0.8 );
        std::getline( in, line );
        student_scores_.push_back( std::atof( line.c_str() ) );
        weighted_.push_back( 0.2 );
        if ( line == "") 
            return false;
        else {      
            compute_score_();
            return true;
        }
  }

};

#endif


