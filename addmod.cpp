#include<iostream>

using namespace std;


double mod(double a, int n){
	long th = a / n;
	double r = a - th * n;
	r < 0 ? r += n : r += 0;
	return r; 
}

int main(){

	double a, b;
	
	int n = 1000000007;

	cin >> a >> b;
	
	cout << (int)mod(mod(a, n) + mod(b, n), n);

	return 0;
}

