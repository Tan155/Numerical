#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float arr[10];
float fx(float x){
	return (float) (pow(x,7) + (2 * pow(x,3)) - 1);
}


float simpson(float a, float b){
	float temp = a, h = (b - a) / 2; 
	for (int i = 0; i <= 2; i++){
		arr[i] = fx(temp); temp += h;
	}
	
	float I = (float) (h / 3) * (arr[0] + (4 * arr[1]) + arr[2]);
	return I; 
}


int main(){
	float I = simpson(-1, 2);
	
	cout << "I >> " << I << endl;
	
	for (int i = 0;i < 5; i++){
    	cout << fixed << setprecision(6) << i << " " << arr[i] << endl;
	}
	cout << (pow(0.5,7) + (2 * pow(0.5,3)) - 1);
	return 0;
}