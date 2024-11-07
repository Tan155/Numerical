#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void gaussJordanElimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        A[i].push_back(b[i]);
    }

    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
                maxRow = k;
            }
        }

        if (maxRow != i) {
            swap(A[i], A[maxRow]);
        }

        double pivot = A[i][i];
        for (int j = i; j < n + 1; ++j) {
            A[i][j] /= pivot;
        }

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j < n + 1; ++j) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }

    vector<double> x(n);
    for (int i = 0; i < n; ++i) {
        x[i] = A[i][n];
    }

    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    vector<vector<double>> A = {
        {0, 2, 0, 1},
        {2, 2, 3, 2},
        {4, -3, 0, 1},
        {6, 1, -6, -5}
    };

    vector<double> b = {0, -2, -7, 6};
	 
    gaussJordanElimination(A, b);

    return 0;
}
