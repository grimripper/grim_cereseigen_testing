#pragma once

#include <Eigen\Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
	MatrixXf m(4, 4);
	m << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;

	cout << m.block<2, 2>(1, 1) << endl;

	m.block<2, 2>(1, 1) << 1, 2, 3, 4;

	cout << m << endl;
}