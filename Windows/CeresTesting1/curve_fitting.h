#pragma once

#pragma warning(push)
#pragma warning(disable : 4996)
#include <ceres\ceres.h>
#pragma warning(pop)

#include <glog\logging.h>
#include <iostream>

using ceres::CostFunction;
using ceres::AutoDiffCostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;

using namespace std;

void run()
{
}
