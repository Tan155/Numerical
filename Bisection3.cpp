#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double func(double x){
	return pow(x,2) - 1;
}


void bisection(double a, double b, double tol){
	double xm, xm_old = 0, i = 0, error;
	do{
		xm = (a + b) / 2;
		if (func(xm) == 0){
			return;
		}
		if (func(xm) * func(b) > 0){
			b = xm;
		}else{
			a = xm;
		}
		
		error = fabs((xm - xm_old) / xm) * 100.0;
		xm_old = xm;
		
		cout << "Iteration " << i+1 << " = " << xm << " Error = " << error << endl;
		i++;
	}while (i != 3);
	
}

void false_position(double a, double b, double tol){
	double xm, xm_old = 0, i = 0, error;
	do{
		xm = (a * func(b) - b * func(a)) / (func(b) - func(a));
		if (func(xm) == 0){
			return;
		}
		if (func(xm) * func(b) > 0){
			b = xm;
		}else{
			a = xm;
		}
		
		error = fabs((xm - xm_old) / xm) * 100.0;
		xm_old = xm;
		
		cout << "Iteration " << i+1 << " = " << xm << " Error = " << error << endl;
		i++;
	}while (i != 3);
	
}
int main(){
	double x1=0, x2 = 1.3, tolrance = 0.000001;
//	double x = bisection(x1,x2,tolrance);
	cout << "Bisection" << endl;
	bisection(x1, x2, tolrance);
	cout << "-------------------" << endl;
	cout << "False Position" << endl;
	false_position(x1,x2,tolrance);
//	cout << fixed << setprecision(6) << x;
	
	
	return 0;
}