#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool choleskyDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = A[i][j];
            for (int k = 0; k < j; k++) {
                sum -= L[i][k] * L[j][k];
            }
            if (i == j) {
                if (sum <= 0) return false;
                L[i][j] = sqrt(sum);
            } else {
                L[i][j] = sum / L[j][j];
            }
        }
    }
    return true;
}

vector<double> solveCholesky(vector<vector<double>>& A, vector<double>& b, int n) {
    vector<vector<double>> L(n, vector<double>(n, 0));
    if (!choleskyDecomposition(A, L, n)) {
        throw runtime_error("Matrix is not positive-definite");
    }

    vector<double> y(n, 0);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }

    vector<double> x(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= L[j][i] * x[j];
        }
        x[i] /= L[i][i];
    }
    
    return x;
}

int main() {
    int n = 3;
    vector<vector<double>> A = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}
    };
    vector<double> b = {9, 0, -4};

    vector<double> x = solveCholesky(A, b, n);

    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }

    return 0;
}
