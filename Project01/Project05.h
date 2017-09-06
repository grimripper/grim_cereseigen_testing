#pragma once

#include <Eigen/Dense>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Eigen;
using namespace std;

void run()
{
	ArrayXXf table(10, 4);
	table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
	table.col(1) = (M_PI / 180) * table.col(0);
	table.col(2) = table.col(1).sin();
	table.col(3) = table.col(1).cos();

	cout << table << endl;
}