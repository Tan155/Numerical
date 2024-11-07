#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double func(double x){
	return (double) 2.0 - exp(-x/4.0);
}

double one_point(double x0,double tol){
	double x1;
	do{
		x1 = (double) func(x0);
		if ( (fabs(x1-x0) / fabs(x1)) * 100 <  tol){
			return x1;
		}
		x0 = x1;
	}while (true);
	
	return x1;
}

int main(){
	double x0 = 8.0, tolerance = 0.000001; // student id 6604062663078
	double sum = one_point(x0,tolerance);
	cout << fixed << setprecision(6) << sum;
	return 0;
}