#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double z, double H) {
    return 200 * (z / 5 - z) * exp(-2 * z / H);
}

double romberg_integration(double a, double b, double H, double tol) {
    const int MAX_LEVELS = 10;
    double R[MAX_LEVELS][MAX_LEVELS] = {0};
    int n = 1;

    // Calculate the first trapezoidal approximation
    R[0][0] = (b - a) * (f(a, H) + f(b, H)) / 2;

    for (int i = 1; i < MAX_LEVELS; ++i) {
        n *= 2;  // Double the number of intervals
        double h = (b - a) / n;
        double sum = 0.0;

        for (int j = 0; j < n; ++j) {
            sum += f(a + (j + 0.5) * h, H);  // Midpoint evaluation
        }

        R[i][0] = R[i - 1][0] / 2 + sum * h;  // Trapezoidal rule

        // Romberg integration
        for (int j = 1; j <= i; ++j) {
            R[i][j] = (4 * R[i][j - 1] - R[i - 1][j - 1]) / (4 * R[i][j - 1] - 1);
        }

        // Check for convergence
        if (fabs(R[i][i] - R[i - 1][i - 1]) < tol * fabs(R[i][i])) {
            return R[i][i];  // Return the result
        }
    }

    return R[MAX_LEVELS - 1][MAX_LEVELS - 1];  // Return the last calculated value
}

int main() {
    double a = 0.0;  // Lower limit
    double b = 30.0; // Upper limit
    double H = 30.0; // Height of the mast
    double tol = 0.005; // Tolerance of 0.5%

    double result = romberg_integration(a, b, H, tol);
    cout << fixed << setprecision(6);
    cout << "Approximate value of F: " << result << endl;

    return 0;
}
