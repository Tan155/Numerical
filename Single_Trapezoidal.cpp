#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float fx(int a){
	float x = (float) ( (4 * pow(a,5)) - (3 * pow(a,4)) + (pow(a,3)) - (6 * a) + 2);
	return x;
}

float integrateFx(int a, int b){
	float A = (float) ( ((4 * pow(a,6)) / 6) - ((3 * pow(a,5)) / 5) + (pow(a,4) / 4) - ((6 * pow(a,2)) / 2) + (2 * a));
	float B = (float) ( ((4 * pow(b,6)) / 6) - ((3 * pow(b,5)) / 5) + (pow(b,4) / 4) - ((6 * pow(b,2)) / 2) + (2 * b));
	
	return B - A;
}

float trapezoidal(int a, int b){
	float x = fx(a);
	float y = fx(b);
	return ((b - a) / 2) * (x + y);
}

float error(int a, int b){
	float x = integrateFx(a,b);
	float y = trapezoidal(a,b);
	return ((x - y) / x) * 100;
}

int main(){
	float i = trapezoidal(2,8);
	float er = error(2,8);
	cout << "I = " << i << endl;
	cout << fixed << setprecision(6) << "Error = " << er << "%"<< endl;
	return 0;
}