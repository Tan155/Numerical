#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double fun(double x){
	return pow(x,2) - 1;
}

double falseposition(double a,double b,double tol){
	double mid,oldmid , fa = fun(a) , fb = fun(b), i = 0;
	do{
		mid = (a * fb - b * fa) / (fb - fa);
		if (fun(mid) * fb == 0){
			break;
		}else if (fun(mid) * fb < 0){
			a = mid;
		}else{
			b = mid;
		}
		
		oldmid = mid;
		mid = (a * fb - b * fa) / (fb - fa);
	}while ( (fabs(mid - oldmid) / fabs(mid)) * 100 >= tol );
	return mid;
}

int main(){
	double a = 0.0,b = 1.3,tolerance = 0.000001 / 100;
	double root = falseposition(a,b,tolerance);
	cout << fixed << setprecision(6) << "Approximate is " << root << endl;
	return 0;
}