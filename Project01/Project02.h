#pragma once

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

void run()
{
	MatrixXd m = MatrixXd::Random(3, 3);
	m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
	cout << m << endl;

	VectorXd v(3);
	v << 1, 2, 3;

	cout << v << endl;

	cout << m*v << endl;
}
