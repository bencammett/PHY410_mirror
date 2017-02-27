#include <iostream>

unsigned int factorial( unsigned int );

int main(void) {
  unsigned int num;
  std::cout << "Enter a number less than 20: ";
  std::cin >> num;
  
  if (num < 20 )
    std::cout << factorial(num) << std::endl;
  else
    std::cout << "Invalid input." << std::endl;

  return 0;

}

unsigned int factorial( unsigned int n ) {
  if (n <= 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return n*factorial(n-1);

}
