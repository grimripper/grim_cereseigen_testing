#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
	typedef Matrix<float, 2, Dynamic> MatrixType;
	typedef Map<MatrixType> MapType;
	typedef Map<const MatrixType> MapTypeConst;   // a read-only map
	const int n_dims = 5;

	MatrixType m1(2,n_dims), m2(2,n_dims);
	m1.setRandom();
	m2.setRandom();
	cout << m1.rows() << "," << m1.cols() << endl;

	float* p = &m2(0);
	MapType m2map(p, m2.rows(), m2.cols());
	cout << m2 << endl;
	cout << m2map << endl;

	cout << (m2 - m2map).squaredNorm() << endl;
	cout << (m1 - m2map).squaredNorm() << endl;
}

