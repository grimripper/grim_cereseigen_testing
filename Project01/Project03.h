#pragma once

#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

void run()
{
	Matrix3d m = Matrix3d::Random();
	m = (m + Matrix3d::Constant(1.2)) * 50;
	Vector3d v(1, 2, 3);
	cout << m << endl;
	//Column-major storage order
	//cout << m(0) << endl;
	//cout << m(1) << endl;
	//cout << m(3) << endl;
	cout << v << endl;
	cout << m*v << endl;
}