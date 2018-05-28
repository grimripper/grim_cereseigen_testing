#pragma once

#include <Eigen/Dense>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Eigen;
using namespace std;

//TODO http://ksimek.github.io/2012/08/22/extrinsic/
Transform<double,3, Affine> Get_Camera_In_World(double angle_in_degrees_around_y, double tx, double ty, double tz)
{
    double angle_in_radians = (M_PI / 180) * angle_in_degrees_around_y;
    AngleAxis<double> aa(angle_in_radians, Vector3d(1, 0, 0));

    Transform<double, 3, Affine> t;
    t = Translation3d(tx, ty, tz) * AngleAxisd(angle_in_radians, Vector3d(0, 1, 0));

    return t;
}

Transform<double, 3, Affine> Get_World_To_Camera_Extrinsic(const Transform<double, 3, Affine>& camera_in_world)
{
    return camera_in_world.inverse();
}

void run()
{
    Transform<double, 3, Affine> transform_y_30_deg_1_0_0 = Get_Camera_In_World(30, 1, 1, 1);

    cout << "Rotation" << endl;
    cout << transform_y_30_deg_1_0_0.rotation() << endl;
    cout << "Translation" << endl;
    cout << transform_y_30_deg_1_0_0.translation() << endl;

    cout << "Floats (col-major storage)" << endl;
    for (int i = 0; i < 16; ++i)
        cout << *(transform_y_30_deg_1_0_0.data() + i) << " " << endl;

    cout << "---Transform pose test---" << endl;
    Vector3d point1(0, 0, 0);
    //SE3_model_to_pose
    Vector3d transformed_point = transform_y_30_deg_1_0_0 * point1;
    cout << "Transform point 1 using transform: (0,0,0) " << endl;
    cout << transformed_point;
}
