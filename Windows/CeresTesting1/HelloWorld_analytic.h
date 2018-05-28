#pragma once

#pragma warning(push)
#pragma warning(disable : 4996)
#include <ceres\ceres.h>
#pragma warning(pop)

#include <glog\logging.h>
#include <iostream>

using ceres::CostFunction;
using ceres::SizedCostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;

using namespace std;

class QuadraticCostFunction : public SizedCostFunction<1, 1> {
public:
    virtual ~QuadraticCostFunction() {}
    virtual bool Evaluate(double const* const* parameters,
        double* residuals,
        double** jacobians) const {
        const double x = parameters[0][0];
        residuals[0] = 10.0 - x;
        if (jacobians != NULL && jacobians[0] != NULL) {
            jacobians[0][0] = -1;
        }
        return true;
    }
};

void run()
{
    double x = 0.5;
    const double initial_x = x;

    Problem problem;

    CostFunction* cost_function = new QuadraticCostFunction;
    problem.AddResidualBlock(cost_function, NULL, &x);

    Solver::Options options;
    //options.linear_solver_type = ceres::DENSE_QR;
    options.sparse_linear_algebra_library_type = ceres::EIGEN_SPARSE;
    options.minimizer_progress_to_stdout = true;
    Solver::Summary summary;
    Solve(options, &problem, &summary);

    cout << summary.BriefReport() << endl;
    cout << "x : " << initial_x << " -> " << x << endl;
}
