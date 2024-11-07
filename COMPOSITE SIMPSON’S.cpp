#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float arr[10];
float fx(float x){
	return (float) (pow(x,7) + (2 * pow(x,3)) - 1);
}


float simpson(float a, float b, int n){
	float temp = a, h = (b - a) / 2, sum_odd, sum_even; 
	for (int i = 0; i <= n; i++){
		arr[i] = fx(temp); temp += h;
	}
	for (int i = 1; i <= n-1; i+=2){
		sum_odd += arr[i];
	}
	
	for (int i = 2; i <= n-2; i+=2){
		sum_even += arr[i];
	}
	
	
	float I = (float) (h / 3) * (arr[0] + arr[n] + (4 * sum_odd) + (2 * sum_even));
	return I; 
}


int main(){
	float I_2 = simpson(-1, 2, 2);
	float I_4 = simpson(-1, 2, 4);
	float I_6 = simpson(-1, 2, 6);
	
	cout << "I_2 >> " << I_2 << endl;
	cout << "I_4 >> " << I_4 << endl;
	cout << "I_6 >> " << I_6 << endl;
	
//	for (int i = 0;i < 5; i++){
//    	cout << fixed << setprecision(6) << i << " " << arr[i] << endl;
//	}
//	cout << (pow(0.5,7) + (2 * pow(0.5,3)) - 1);
	return 0;
}