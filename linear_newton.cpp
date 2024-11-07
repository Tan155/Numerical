#include<iostream>
#include<cmath>
using namespace std;


float x_val[] = {0 ,20000, 40000, 60000, 80000};
float y[] = {9.81, 9.7487, 9.6879, 9.6879, 9.5682};

float newton_linear(int p1, int p2, float x){
	float x0 = x_val[p1];
	float x1 = x_val[p2];
	float y0 = y[p1];
	float y1 = y[p2];
	float newton = y0 + ((y1 - y0) / (x1 - x0)) * (x - x0);
	return newton;
}
int main(){
	float new_ton = newton_linear(0, 4, 42000);
	cout << new_ton << endl;
	return 0;
}#include<iostream>
#include<cmath>
using namespace std;


float x_val[] = {0 ,20000, 40000, 60000, 80000};
float y[] = {9.81, 9.7487, 9.6879, 9.6879, 9.5682};

float newton_linear(int p1, int p2, float x){
	float x0 = x_val[p1];
	float x1 = x_val[p2];
	float y0 = y[p1];
	float y1 = y[p2];
	float newton = y0 + ((y1 - y0) / (x1 - x0)) * (x - x0);
	return newton;
}
int main(){
	float new_ton = newton_linear(0, 4, 42000);
	cout << new_ton << endl;
	return 0;
}