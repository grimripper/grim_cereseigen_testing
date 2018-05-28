#pragma once

#pragma warning(push)
#pragma warning(disable : 4996)
#include <ceres\ceres.h>
#pragma warning(pop)

#include <glog\logging.h>
#include <iostream>

using ceres::AutoDiffCostFunction;
using ceres::NumericDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;

using namespace std;

struct CostFunctor {
    template <typename T>
    bool operator()(const T* const x, T* residual) const {
        residual[0] = 10.0 - x[0];
        return true;
    }
};

struct NumericDiffCostFunctor {
    template <typename T>
    bool operator()(const T* const x, T* residual) const {
        residual[0] = 10.0 - x[0];
        return true;
    }
};

void run()
{
    double x = 0.5;
    const double initial_x = x;

    Problem problem;

    //CostFunction* cost_function = new AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);
    //problem.AddResidualBlock(cost_function, NULL, &x);

    CostFunction* cost_function = new NumericDiffCostFunction<NumericDiffCostFunctor, ceres::CENTRAL, 1, 1>(new NumericDiffCostFunctor);
    problem.AddResidualBlock(cost_function, NULL, &x);

    Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    //options.sparse_linear_algebra_library_type = ceres::EIGEN_SPARSE;
    options.minimizer_progress_to_stdout = true;
    Solver::Summary summary;
    Solve(options, &problem, &summary);

    cout << summary.BriefReport() << endl;
    cout << "x : " << initial_x << " -> " << x << endl;
}
