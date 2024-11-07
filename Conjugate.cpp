#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;


vector<double> conjugateGradient(const vector<vector<double>>& A, const vector<double>& b, int n, int maxIterations, double tolerance) {
    vector<double> x(n, 0);
    vector<double> r = b;
    vector<double> p = b;

    double rNorm = sqrt(inner_product(r.begin(), r.end(), r.begin(), 0.0));
    if (rNorm < tolerance) {
        return x;
    }

    for (int iter = 0; iter < maxIterations; ++iter) {
        vector<double> Ap(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                Ap[i] += A[i][j] * p[j];
            }
        }

        double alpha = inner_product(r.begin(), r.end(), r.begin(), 0.0) / inner_product(p.begin(), p.end(), Ap.begin(), 0.0);

        for (int i = 0; i < n; ++i) {
            x[i] += alpha * p[i];
        }

        for (int i = 0; i < n; ++i) {
            r[i] -= alpha * Ap[i];
        }

        double rNormNew = sqrt(inner_product(r.begin(), r.end(), r.begin(), 0.0));
        if (rNormNew < tolerance) {
            return x;
        }

        double beta = inner_product(r.begin(), r.end(), r.begin(), 0.0) / (rNorm * rNorm);

        for (int i = 0; i < n; ++i) {
            p[i] = r[i] + beta * p[i];
        }

        rNorm = rNormNew;
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

    vector<double> x = conjugateGradient(A, b, n, maxIterations, tolerance);

    cout << "Conjugate Gradient solution x:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
