#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double fun(double x){
	return pow(x,4) - 13;
}

double bisection(double a, double b, double tol){
	double mid, oldmid;
	do{
		mid = (a + b) / 2.0;
		if (fun(mid) * fun(b) == 0){
			break;
		}else if (fun(mid) * fun(b) > 0){
			b = mid;
		}else{
			a = mid;
		}
		oldmid = mid;
		mid = (a + b) / 2.0;
	}while ((fabs(mid - oldmid) / fabs(mid)) * 100 >= tol);
	
	return mid;
}

int main(){
	double a = 1.5, b = 2.0, tolerance = 1e-7;
	double root = bisection(a,b,tolerance);
	
	cout << fixed << setprecision(6) << "Approximate root " << root << endl;
	return 0;
}