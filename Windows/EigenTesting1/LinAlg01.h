#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
    Matrix3f A;
    Vector3f b;
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 10;

    b << 3, 3, 4;

    cout << A << endl;
    cout << b << endl;

    {
        cout << "COLPIVHOUSEHOLDERQR - fast and accurate, no requirements on matrix" << endl;
        Vector3f x = A.colPivHouseholderQr().solve(b);
        cout << "x = " << x << endl;

        ColPivHouseholderQR<Matrix3f> dec1(A);
        Vector3f y = dec1.solve(b);
        cout << "x = " << y << endl;

        ColPivHouseholderQR<Matrix3f> dec2;
        dec2.compute(A);
        cout << "x = " << dec2.solve(b) << endl;
    }

    {
        cout << "FULLPIVHOUSEHOLDERQR - slow but accurate, no requirements on matrix" << endl;
        Vector3f x = A.fullPivHouseholderQr().solve(b);
        cout << "x = " << x << endl;
    }

    {
        cout << "FULLPIVLU - slow but accurate, no requirements on matrix" << endl;
        FullPivLU<Matrix3f> fplu;
        fplu.compute(A);
        cout << "x = " << fplu.solve(b) << endl;
    }

    {
        //Must be invertible
        cout << "PARTIALPIVLU - Fast, Matrix must be invertible" << endl;
        PartialPivLU<Matrix3f> pplu;
        pplu.compute(A);
        cout << "x = " << pplu.solve(b) << endl;
    }

    {
        cout << "JacobiSVD - slow, accurate" << endl;
        MatrixXf A1(3,3);
        A1 = A;
        cout << "x = " << A1.jacobiSvd(ComputeThinU | ComputeThinV).solve(b) << endl;
    }

    Matrix3f AtA = A.transpose() * A;
    {
        cout << "COLPIVHOUSEHOLDERQR on AtA" << endl;
        Vector3f x = AtA.colPivHouseholderQr().solve(b);
        cout << "x = " << x << endl;
    }

    {
        cout << "LLT on AtA - must be positive definite (less accurate)" << endl;
        Vector3f x = AtA.llt().solve(b);
        cout << "x = " << x << endl;
    }

    {
        cout << "LDLT on AtA - must be positive/negative semidefinite (more accurate)" << endl;
        Vector3f x = AtA.ldlt().solve(b);
        cout << "x = " << x << endl;
    }
}
