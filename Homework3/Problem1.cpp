#include <iostream>
#include <cmath>
#include <list>

//float looping( float );

int main(void){
  float xi, yi, mag;
  std::cout << "Enter a letter to exit." << std::endl;
  std::cout << "Please enter values with spaces as x1 y1 x2 y2 x3 y3 ... ";
  while( std::cin >> xi >> yi ){

    // if {

     mag = sqrt ((pow (xi, 2.0)) + (pow (yi, 2.0)));
      
     /* 
     for ( mag; mag > 0; mag-- ) {
       std::cout << mag << std::endl;
     }
     */
     

     /*
     std::list<float> min_mag;
     min_mag.assign (mag);
     std::cout << "So far: " << min_mag << std::endl;
     */
    
     std::cout << "x = " <<  xi  << ", y = " << yi << std::endl;
     std::cout << "Magnitude is: " << mag << std::endl;
     // }
  }

  return 0;
}

  /*
  std::list<int> find_min_list;
  find_min_list.insert (mag);
  std::cout << find_min_list << std::endl;
  */



// ref: http://www.cplusplus.com/ for pow and sqrt





/*
float looping( float diff ){
  //float diff;
  float xi, yi;
  diff = yi - xi;
  return diff;
}
*/

/*
int main(){
  int vec1, vec2, diff;
  std::cout << "Enter input as vec1 vec2 with spaces: ";
  std::cin >> vec1, vec2;
  diff = (vec2 - vec1);
  for (diff; diff < 10; ++diff) {
    std::cout << diff << std::endl;
  }
  //  std::cout << std::endl;  
}
*/



