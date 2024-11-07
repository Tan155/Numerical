#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main() {
    Matrix3d A;
    Vector3d B;

    A << -2, 3, 1,
         3, 4, -5,
         1, -2, 1;

    B << 9, 0, -4;
    
    Matrix3d A_inv = A.inverse();

    Vector3d X = A_inv * B;

    cout << "Solution (x1, x2, x3) = " << X.transpose() << endl;

    return 0;
}
