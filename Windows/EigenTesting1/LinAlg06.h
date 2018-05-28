#pragma once

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

void doStuff(const MatrixXf& m22)
{
    cout << "Here is the matrix m:" << endl << m22 << endl;
    JacobiSVD<MatrixXf> svd_A(m22, ComputeThinU | ComputeThinV);
    cout << "Its singular values are:" << endl << svd_A.singularValues() << endl;
    cout << "Its left singular vectors are the columns of the thin U matrix:" << endl << svd_A.matrixU() << endl;
    cout << "Its right singular vectors are the columns of the thin V matrix:" << endl << svd_A.matrixV() << endl;

    //Vector2f vec = svd.matrixV().row(0);
    //cout << vec << endl;

    cout << endl << m22 * svd_A.matrixV().col(0) << endl;
    cout << endl << svd_A.singularValues()(0) * svd_A.matrixU().col(0) << endl;
    cout << endl << m22 * svd_A.matrixV().col(1) << endl;
    cout << endl << svd_A.singularValues()(1) * svd_A.matrixU().col(1) << endl;

    EigenSolver<MatrixXf> eigen_solver_A;
    eigen_solver_A.compute(m22);
    cout << "eigenvalues: " << endl;
    cout << endl << eigen_solver_A.eigenvalues() << endl;
    cout << "eigenvectors: " << endl;
    cout << endl << eigen_solver_A.eigenvectors() << endl;

    cout << endl << m22 * eigen_solver_A.eigenvectors().col(0) << endl;
    cout << endl << eigen_solver_A.eigenvalues()(0) * eigen_solver_A.eigenvectors().col(0) << endl;
    cout << endl << m22 * eigen_solver_A.eigenvectors().col(1) << endl;
    cout << endl << eigen_solver_A.eigenvalues()(1) * eigen_solver_A.eigenvectors().col(1) << endl;
}

void run()
{
    MatrixXf m82 = MatrixXf::Random(8, 2);
    Matrix2f m22 = MatrixXf::Random(2, 2);
    Matrix2f m22_t_m22 = m22.transpose() * m22;

    //For A - eigenvectors don't really work - why?
    cout << "-----" << endl;
    cout << "  A" << endl;
    cout << "-----" << endl;
    doStuff(m22);

    //For A'A
    cout << "-----" << endl;
    cout << " AtA " << endl;
    cout << "-----" << endl;
    doStuff(m22_t_m22);
}
