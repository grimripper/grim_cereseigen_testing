#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
    MatrixXf A = MatrixXf::Random(3, 2);
    MatrixXf b = VectorXf::Random(3);

    VectorXf x = A.colPivHouseholderQr().solve(b);
    cout << "Solution (QR): " << endl
        << x
        << endl;

    cout << "Solution (SVD): " << endl
        << A.jacobiSvd(ComputeThinU | ComputeThinV | ComputeEigenvectors).solve(b) 
        << endl;

    MatrixXf AtA = A.transpose() * A;
    x = AtA.inverse() * A.transpose() * b;

    cout << "Solution (normal equation): " << endl
        << x
        << endl;

    cout << "Solution (normal equation + LDLT): " << endl
        << (AtA).ldlt().solve(A.transpose()*b)
        << endl;

    cout << "Error: " << endl
        << (A*x - b).norm() / b.norm()
        << endl;
}
