#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
    MatrixXd A = MatrixXd::Random(100, 100);
    MatrixXd b = MatrixXd::Random(100, 50);
    MatrixXd x = A.fullPivLu().solve(b);

    double relative_error = (A*x - b).norm() / b.norm();
    cout << relative_error << endl;
}
