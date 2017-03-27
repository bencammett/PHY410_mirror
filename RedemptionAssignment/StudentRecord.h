#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H


#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


class StudentRecord {

 public:
    StudentRecord();
    ~StudentRecord(){};
    
    double score() const;

    bool operator<( StudentRecord const & right ) const;

    virtual void print( std::ostream & out = std::cout ) const = 0;
    // for purposes of polymorphism, abstract base with pure virtual functions
    virtual bool input( std::istream & in ) = 0;
    // need to access with pointers



 protected: // so that derived classes have access
    std::string firstname_;
    std::string lastname_;
    std::vector<double> student_scores_;    // store individual student score
    std::vector<double> weighted_;
    double score_;                          // average score
    
    void compute_score_(void);
};


#endif


