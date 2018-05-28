#include "ceres/ceres.h"
#include "glog/logging.h"
#include <iostream>
using namespace std;
using namespace ceres;

class QuadraticCostFunction : public ceres::SizedCostFunction<1,1> {
public:
    virtual ~QuadraticCostFunction() {}
    virtual bool Evaluate(double const* const* parameters,
                          double* residuals,
                          double** jacobians) const {
        const double x = parameters[0][0];
        residuals[0] = 10 - x;

        //Compute Jacobians if asked for
        if (jacobians != NULL && jacobians[0] != NULL) {
            jacobians[0][0] = -1;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);

    double initial_x = 5.0;
    double x = initial_x;

    Problem problem;
    CostFunction* cost_function = new QuadraticCostFunction;
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

