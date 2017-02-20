#include <iostream>
#include <iomanip>
#include <cmath>


int main() {
  float x1, y1, x2, y2, slope, y_int, mid_x, mid_y, numerator, denominator, perp_line_slope, y_int_perp;
  float tolerance = 0.00001;
  std::cout << std::setprecision(5);
  std::cout << "Note: Precision had been set to 5." << std::endl;
  std::cout << "Please enter your values, in order x1 y1 x2 y2, with spaces: ";
  std::cin >> x1 >> y1 >> x2 >> y2;

  
  numerator = (y2 - y1);
  denominator = (x2 - x1);


  std::cout << "Your entered values are: x1 = " << x1 << ", y1 = " << y1 << ", x2 = " << x2 << ", y2 = " << y2 << std::endl;


  if ( denominator == 0 ) {
    std::cout << "WARNING: Your denominator evaluates to zero, this is undefined, please pick different values." << std::endl;
    } 
  else if ( std::abs(y1 - x1) < tolerance ) {
    std::cout << "Bad values. Below tolerance. Did you enter a letter or character? Ha!" << std::endl;
    }
  else {
    slope = (numerator) / (denominator);
    mid_x = (x2 + x1) / 2.0;
    mid_y = (y2 + y1) / 2.0;
    y_int = y1 - (slope * x1);
    perp_line_slope = slope * (-1);
    y_int_perp = y1 - (perp_line_slope * x1);
    std::cout << "Your slope is: " << slope << std::endl;
    std::cout << "Your y-int is: " << y_int << std::endl;
    std::cout << "Your midpoint in (x,y) is: " << "(" << mid_x << "," << mid_y << ")" << std::endl;
    std::cout << "Your equation is: " << "y = " << slope << "x" << " + " << y_int << std::endl;
    std::cout << "Line perpendicular & passes through first point: " << "y = " << perp_line_slope << "x" << " + " << y_int_perp << std::endl;
    }
}

// Log: (Excluding minor runs.)
// Run1: some weird output, no spaces...
// Run2: too ambitious w/ different functions, reducing to one
// Run3: missed a few syntax issues
// Run4: int --> float, got rid of slope is zero problem (truncation)
// Run5: handels negative fine
// Run6: if else works perfect, gave me error for 0 in denominator
// Run7: gave it floats, handled well
// Run8: equation pops out well, cleaned up presentation
// Run9: midpoint calculation works fine, ints and floats, + and -
// Run10: was stuck on y_int, turns out had simple solution, I'm stupid, all works fine now
// Run11: perp_line stuff works fine
// Run12: set precision just to be sure, notified user
// Run13: used tolerance to fix letter input problem -- entering a letter makes y1 super small, i.e., below tolerance
// End Log: removed excess comments.

/* 
   Written by Benjamin Cammett
   PHY 410: Computational Physics
   Instructor: Professor Salvatore Rappoccio
   Institution: University at Buffalo
*/
