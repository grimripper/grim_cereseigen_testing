#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void run()
{
	VectorXf v(2);
	MatrixXf m(2, 2), n(2, 2);

	v << -1,
		2;

	m << 1, -2,
		-3, 4;

	cout << "v = " << v << endl;
	cout << "v.squaredNorm() = " << v.squaredNorm() << endl;
	cout << "v.norm() = " << v.norm() << endl;
	cout << "v.lpNorm<1>() = " << v.lpNorm<1>() << endl;
	cout << "v.lpNorm<Infinitiy>() = " << v.lpNorm<Infinity>() << endl;
}