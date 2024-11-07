#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double func(double x){
	return pow(x,2) - 7; // root7 = x >> 7 = x^2 >> x^2 - 7 = 0
}

double calculus(double x){
	return 2 * x;
}

double Newton_Raphson(double x0, double tol){
	double x1, i = 0;
	do{
		x1 = x0 - (func(x0) / calculus(x0));
		if (fabs(x1 - x0) < tol){
			break;
		}
		x0 = x1;
		i++;
		if (i == 1000){
			break;
		}
	}while (true);
	
	return x1;
}

int main(){
	double x0 = 2.0, tolerance = 0.000001;
	double sum = Newton_Raphson(x0,tolerance);
	cout << fixed << setprecision(6) << sum;
}