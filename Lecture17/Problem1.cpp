#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "nonlin.hpp"
using namespace cpt;

double V(double r)
{
    double x;
    double y;
    r = pow( pow(x, 2.0) + pow(y, 2.0) , 0.5 );
    return -pow(r, 2.0)/ 2 + pow(r, 4.0)/4;
}

int main()
{
    double acc = 1e-6;
    double guess1 = 0.1, guess2 = -0.1;
    double r_min;
    double V_min = find_minimum< double (*)(double)> (guess1, guess2, V, acc, r_min);
    cout << "V(x,y) = " << V_min << " at r = " << r_min << endl;

    double r_max;
    double V_max = find_maximum< double (*)(double)> (guess1, guess2, V, acc, r_max);
    cout << "V(x,y) = " << V_max << " at r = " << r_max << endl;
}
