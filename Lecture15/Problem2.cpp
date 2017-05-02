#include <iostream>
using namespace std;

#include "linalg.hpp"
using namespace cpt;

int main()
{

    // m1 is Carbon, m2 is Oxygen, mass in units of standard atomic weight
    double m1 = 12.0, m2 = 15.9;

    // Matrix with masses as the diagonal elements
    Matrix<double,2> M(5, 5);
    M(0,0) = m1;
    M(1,1) = m2;
    M(2,2) = m2;
    M(3,3) = m2;
    M(4,4) = m1;
    cout << "M =\n" << M;


    Matrix<double,2> Minv(5,5);
    inverse(M, Minv);
    cout << "Minv=" << endl << Minv << endl;

    // "Spring" constants affecting each mass
    // k12 is carbon to oxygen, k23 is carbon to carbon
    double k12 = 15.0, k23 = 12.69;
    double Lagrange[5][5] = {
        {   k12,    -k12,       0,      0,          0     },
        {   -k12,   k12 + k23,  -k23,   0,          0     },
        {   0,      -k23,       2*k23,  -k23,       0     },
        {   0,      0,          -k23,   k12 + k23,  -k12  },
        {   0,      0,          0,      0,          -k12  }
    };
    Matrix<double,2> K(5, 5);
    for (int i = 0; i < 4+1; i++)
        for (int j = 0; j < 4+1; j++)
            K(i,j) = Lagrange[i][j];
    cout << "K =\n" << K;




    // Solve with generalized eigenvector solution
    Matrix<double,1> eigenvalues = solve_eigen_generalized(K, M, true);

    cout << "Eigenvalues =\n" << eigenvalues << endl
         << "Eigenvectors =\n" << K;


}
