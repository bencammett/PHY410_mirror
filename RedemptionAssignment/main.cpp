#include "StudentRecordPhysics.h"
#include "StudentRecordHistory.h"
#include "StudentRecordLiterature.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>


float cal_avg( std::vector<std::shared_ptr<StudentRecord> > const & records );

bool compare_scores(std::shared_ptr<StudentRecord> const & lhs, std::shared_ptr<StudentRecord> const & rhs);

int main(int argc, char * argv[]) {

    if ( argc < 2 ) {
        std::cout << "Error, need text file as well." << std::endl;
        return 0;
  }

    std::ifstream fin( argv[1] );

    std::vector<std::shared_ptr<StudentRecord> > records, physics, literature, history;
    
//////////////////////////////////////////////////////////////

  bool valid = true;
  while( valid ) {
    std::string line;
    std::getline( fin, line, ',');
    if ( line == "" ) 
      break;

    if ( line == "Physics" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordPhysics() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	physics.push_back( irecord );
      }
      else
	break;
    } else if ( line == "Literature" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordLiterature() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	literature.push_back( irecord );
      }
      else
	break;
    } else if ( line == "History" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordHistory() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	history.push_back( irecord );
      }
      else
	break;
    } else {
      std::cout << "Invalid input, ignoring" << std::endl;
      continue;
    }

  }

 
////////////////////////////////////////////////////////////


    std::cout << std::endl;
    std::cout << "Printing and sorting by total grade..." << std::endl;
    std::cout << "Total grade displayed, least to greatest." << std::endl;
    std::cout << std::endl;

    std::cout << "Physics Class List:" << std::endl;
    std::sort( physics.begin(), physics.end(), compare_scores );
    std::cout << "Class average: " << cal_avg( physics ) << std::endl;
    for ( std::shared_ptr<StudentRecord> const & rec : physics ) {
        rec->print( std::cout );
    }
    
    std::cout << std::endl;

    std::cout << "History Class List:" << std::endl;
    std::sort( history.begin(), history.end(), compare_scores );
    std::cout << "Class average: " << cal_avg( history ) << std::endl;
    for ( std::shared_ptr<StudentRecord> const & rec : history ) {
        rec->print( std::cout );
    }
    
    std::cout << std::endl;

    std::cout << "Literature Class List:" << std::endl;
    std::sort( literature.begin(), literature.end(), compare_scores );
    std::cout << "Class average: " << cal_avg( literature ) << std::endl;
    for ( std::shared_ptr<StudentRecord> const & rec : literature ) {
        rec->print( std::cout );
    }
    
    std::cout << std::endl;

    std::cout << "All Students List:" << std::endl;
    std::sort( records.begin(), records.end(), compare_scores );
    std::cout << "Overall average: " << cal_avg( records ) << std::endl;
    for ( std::shared_ptr<StudentRecord> const & rec : records ) {
        rec->print( std::cout );
    }

}


bool compare_scores(std::shared_ptr<StudentRecord> const & lhs, std::shared_ptr<StudentRecord> const & rhs) {
        return *lhs < *rhs;
}

float cal_avg( std::vector<std::shared_ptr<StudentRecord> > const & records ) {

    float avg = 0.;
    if ( records.size() == 0 ) {
        std::cout << "Error, none given." << std::endl;
        return avg;
    }
    for ( auto const & rec : records ) {
        avg += rec->score();
    }
    avg /= records.size();
    return avg;

}





