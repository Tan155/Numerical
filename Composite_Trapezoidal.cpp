#include <iostream>
#include <cmath>
using namespace std;
float arr[10];
double f(double x) {
    return (4 * pow(x, 5)) - (3 * pow(x, 4)) + (pow(x, 3)) - (6 * x) + 2;
}

double compositeTrapezoidal(double a, double b, int n) {
	float h = (b - a) / n, sum, temp = a;
	for (int i = 0; i <= n; i++){
		arr[i] = f(temp); temp += h;
	}
	
	for (int i = 1; i <= n-1; i++){
		sum += arr[i];
	}
	
	float I = (h / 2) * (arr[0] + arr[n] + 2 * sum);
	
	return I;
	
}

int main() {
    double a = 2.0;
    double b = 8.0;
    int n_2 = 2, n_4 = 4, n_6 = 6; 

    double integral_2 = compositeTrapezoidal(a, b, n_2);
    double integral_4 = compositeTrapezoidal(a, b, n_4);
    double integral_6 = compositeTrapezoidal(a, b, n_6);
    cout << "n = 2 >> " << integral_2 << endl;
    cout << "n = 4 >> " << integral_4 << endl;
    cout << "n = 6 >> " << integral_6 << endl;
    
    
//    for (int i = 0;i < 5; i++){
//    	cout << i << " " << arr[i] << endl;
//	}

    return 0;
}
