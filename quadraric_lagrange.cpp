#include<iostream>
#include<cmath>
using namespace std;

float x_val[] = {-100, 0, 100, 200, 300, 400};
float y[] = {215, 202, 206, 215, 228, 249};

	
float lagrange(int p1, int p2, int p3, float x){
	float x0 = x_val[p1], x1 = x_val[p2], x2 = x_val[p3];
	float fx0 = y[p1], fx1 = y[p2], fx2 = y[p3];
	float lan = (( ((x2 - x) * (x1 - x)) / ((x2 - x0) * (x1 - x0)) ) * fx0) +
				(( ((x2 - x) * (x0 - x)) / ((x2 - x1) * (x0 - x1)) ) * fx1) +
				(( ((x1 - x) * (x0 - x)) / ((x1 - x2) * (x0 - x2)) ) * fx2); 
	return lan;
}

int main(){
	float lan = lagrange(0, 2, 5, 250);
	cout << lan << endl;
	return 0;
}