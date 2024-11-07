#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> gaussSeidel(const vector<vector<double>>& A, const vector<double>& b, int n, int maxIterations, double tolerance) {
    vector<double> x(n, 0);

    for (int iter = 0; iter < maxIterations; ++iter) {
        vector<double> xOld = x;
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double maxError = 0;
        for (int i = 0; i < n; ++i) {
            maxError = max(maxError, abs(x[i] - xOld[i]));
        }
        if (maxError < tolerance) {
            return x;
        }
    }

    return x;
}

int main() {
    int n = 4;
    vector<vector<double>> A = {
        {5, 2, 0, 0},
        {2, 5, 2, 0},
        {0, 2, 5, 2},
        {0, 0, 2, 5}
    };
    vector<double> b = {12, 17, 14, 7};

    int maxIterations = 1000;
    double tolerance = 1e-6;

    vector<double> x = gaussSeidel(A, b, n, maxIterations, tolerance);

    cout << "Gauss-Seidel solution x:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}