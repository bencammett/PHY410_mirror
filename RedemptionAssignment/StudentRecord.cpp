#include "StudentRecord.h"

StudentRecord::StudentRecord(){}


double StudentRecord::score() const {
    return score_;
}

bool StudentRecord::operator<( StudentRecord const & right ) const {
  return this->score() < right.score();
}

void StudentRecord::compute_score_(void) {
    score_ = 0.;
    for (unsigned int i = 0; i < student_scores_.size(); ++i) {
        double score = student_scores_[i];
        double weight = weighted_[i];
        score_ += score * weight;    
  }  
}




