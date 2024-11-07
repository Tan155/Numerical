#include <iostream>
#include <vector>

using namespace std;

double determinant3x3(vector<vector<double>>& mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

double determinant4x4(vector<vector<double>>& matrix) {
    double det = 0;
    vector<vector<double>> submatrix(3, vector<double>(3));

    for (int i = 0; i < 4; ++i) {
        int subi = 0;
        for (int j = 1; j < 4; ++j) {
            int subj = 0;
            for (int k = 0; k < 4; ++k) {
                if (k == i) continue;
                submatrix[subi][subj++] = matrix[j][k];
            }
            ++subi;
        }
        double subdet = determinant3x3(submatrix);
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * subdet;
    }
    
    return det;
}

void cramer4x4(vector<vector<double>>& A, vector<double>& b) {
    double detA = determinant4x4(A);

    if (detA == 0) {
        cout << "CANNOT FIND" << endl;
        return;
    }

    vector<double> x(4);

    for (int i = 0; i < 4; ++i) {
        vector<vector<double>> Ai = A;
        for (int j = 0; j < 4; ++j) {
            Ai[j][i] = b[j];
        }
        double detAi = determinant4x4(Ai);
        x[i] = detAi / detA;
    }

    for (int i = 0; i < 4; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    vector<vector<double>> A = {
        {6, -2, 2, 4},
        {12, -8, 6, 10},
        {3, -13, 9, 3},
        {-6, 4, 1, -18}
    };

    vector<double> b = {16, 26, -19, -34};

    cramer4x4(A, b);

    return 0;
}
