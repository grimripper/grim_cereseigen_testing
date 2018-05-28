#include "ceres/ceres.h"
#include "glog/logging.h"
#include <iostream>
using namespace std;
using namespace ceres;

struct NumericDiffCostFunctor {
    bool operator()(const double* const x, double* residual) const {
        residual[0] = 10.0 - x[0];
        return true;
    }
};

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);

    double initial_x = 5.0;
    double x = initial_x;

    Problem problem;
    CostFunction* cost_function = new NumericDiffCostFunction<NumericDiffCostFunctor, ceres::CENTRAL, 1,1>(new NumericDiffCostFunctor);
    problem.AddResidualBlock(cost_function, NULL, &x);

    Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    cout << summary.BriefReport() << endl;
    cout << "x: " << initial_x << "->" << x << endl;

    return EXIT_SUCCESS;
}

