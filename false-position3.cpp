#include <iostream>
#include <cmath>

using namespace std;

// Define the function f(x) = x^2 - 1
double f(double x) {
    return x*x - 1;
}

// False Position method to find root of f(x) in [a, b] with tolerance
double falsePositionMethod(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "False Position method cannot guarantee a root in the given interval." << endl;
        return NAN; // or some error handling
    }

    double c = 0.0; // Initialize variable for new estimate
    int iter = 0; // Iteration counter

    while (fabs(b - a) >= tolerance * fabs(b + a)) {
        // Calculate the new estimate using linear interpolation
        c = a - (f(a) * (b - a)) / (f(b) - f(a));

        // Check if new estimate is the root
        if (f(c) == 0.0) {
            return c;
        }
        // Update interval [a, b] based on the sign of f(c)
        else if (f(c) * f(a) < 0) {
            b = c; // Root lies between a and c
        } else {
            a = c; // Root lies between c and b
        }

        iter++;
    }

    // Return the approximate root found
    return c;
}

int main() {
    double a = 0.0; // Lower bound of the interval
    double b = 1.3; // Upper bound of the interval
    double tolerance = 0.000001; // Tolerance for stopping criteria

    // Find root using false position method
    double root = falsePositionMethod(a, b, tolerance);

    cout << "Approximate root found by False Position method: " << root << endl;

    return 0;
}
