#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                L[j][i] = 0;
            } else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (j < i) {
                U[i][j] = 0;
            } else if (j == i) {
                U[i][j] = 1;
            } else {
                U[i][j] = A[i][j];
                for (int k = 0; k < i; k++) {
                    U[i][j] -= L[i][k] * U[k][j];
                }
                U[i][j] /= L[i][i];
            }
        }
    }
}

vector<double> solveLU(vector<vector<double>>& A, vector<double>& b, int n) {
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));
    luDecomposition(A, L, U, n);

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
            x[i] -= U[i][j] * x[j];
        }
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

    vector<double> x = solveLU(A, b, n);

    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }

    return 0;
}
