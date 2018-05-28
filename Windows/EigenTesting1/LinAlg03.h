#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
    Matrix2f A;
    A << 1, 2,
         2, 3;

    cout << "A = " << endl << A << endl;

    SelfAdjointEigenSolver<Matrix2f> eigenSolver(A);
    if (eigenSolver.info() != Success) abort();

    cout << "Eigen values of A are: " << endl << eigenSolver.eigenvalues() << endl;
    cout << "Eigen vector matrix (columns are eigen vectors): " << endl << eigenSolver.eigenvectors() << endl;

    cout << "Ax = " << endl;
    cout << A * eigenSolver.eigenvectors().col(0) << endl;
    cout << "lambda.x = " << endl;
    cout << eigenSolver.eigenvalues()(0) * eigenSolver.eigenvectors().col(0) << endl;
    cout << "Ax = " << endl;
    cout << A * eigenSolver.eigenvectors().col(1) << endl;
    cout << "lambda.x = " << endl;
    cout << eigenSolver.eigenvalues()(1) * eigenSolver.eigenvectors().col(1) << endl;

    cout << "Determinant of A = " << A.determinant() << endl;
    cout << "Inverse of A = " << endl << A.inverse() << endl;

    {
        Matrix3f B;
        B << 1, 2, 5,
            2, 1, 4,
            3, 0, 3;
        cout << "B = " << endl << B << endl;

        FullPivLU<Matrix3f> lu_decomp(B);
        cout << lu_decomp.matrixLU() << endl;
        cout << lu_decomp.rank() << endl;

        cout << "Null space of A = " << endl << lu_decomp.kernel() << endl;
        cout << "Column space of A = " << endl << lu_decomp.image() << endl;
    }
}
