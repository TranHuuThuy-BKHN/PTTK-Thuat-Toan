#include<iostream>


using namespace std;


double mod_string(int a, int b, int m){
	double s = 1.0;
	for(int i = 0; i < b; i++){
		s = s * a;
		s = s - (double)(int(s/m)) * m;
	}
	
	return s;
}

int main(){

	int m = 1000000007, a, b;
	cin >> a >> b;
	cout << int(mod_string(a, b, m));
	
	return 0;
}
