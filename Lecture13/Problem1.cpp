#include <cmath>
#include <iostream>
using namespace std;
 
#include "linalg.hpp"
using namespace cpt;
 
int main()
{
    cout << " Unbalanced Wheatstone bridge equations\n"
         << " --------------------------------------\n";
 
    double v0 = 1.0,
           r = 1.0,
           r1 = r,
           r2 = r,
           r3 = r,
           r4 = r,
           r5 = r,
           r6 = r,
           r7 = r,
           r8 = r,
           r9 = r,
           r10 = r,
           r11 = r,
           r12 = r;
 
    Matrix<double,2> v(6, 1);
    v[0][0] = v0;
    cout << " v = \n" << v << endl;
    cout << "v.dim1 = " << v.dim1() << endl;
 
    Matrix<double,2> R(6, 6);
    R[0][0] = r1;
    R[0][1] = r1 + r4 + r7;
    R[0][2] = 0;
    R[0][3] = r8;
    R[0][4] = 0;
    R[0][5] = 0;
 
    R[1][0] = r1 + r5 + r10;
    R[1][1] = r1;
    R[1][2] = 0;
    R[1][3] = 0;
    R[1][4] = r10;
    R[1][5] = 0;
    
    R[2][0] = 0;
    R[2][1] = 0;
    R[2][2] = r2 + r6 + r9;
    R[2][3] = r2;
    R[2][4] = 0;
    R[2][5] = r12;

    R[3][0] = 0;
    R[3][1] = r7;
    R[3][2] = r2;
    R[3][3] = r2 + r7 + r8;
    R[3][4] = 0;
    R[3][5] = 0;

    R[4][0] = r10;
    R[4][1] = 0;
    R[4][2] = 0;
    R[4][3] = 0;
    R[4][4] = r3 + r7 + r10;
    R[4][5] = r3;

    R[5][0] = 0;
    R[5][1] = 0;
    R[5][2] = r9;
    R[5][3] = 0;
    R[5][4] = r3;
    R[5][5] = r3 + r12 + r9;
 
    cout << " R = \n" << R << std::endl;
    cout << " R.dim1 = " << R.dim1() << endl;
    cout << " R.dim2 = " << R.dim2() << endl;
 
    // the solve_Gauss_Jordan replaces R by R^-1 and v by i
    // so save the original R and copy v into a vector i
    Matrix<double,2> R_save(R), i(v);
 
    solve_Gauss_Jordan(R, i);
    cout << " Solution using Gauss-Jordan elimination\n i = \n"
         << i << endl;
 
 
    // see whether LU decomposition gives the same answer
    i = v;
    solve_LU_decompose(R_save, i);
    cout << " Solution using LU Decompositon\n i = \n"
         << i << endl;
}
