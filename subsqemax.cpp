#include<iostream>

using namespace std;

//6
//-2 11 -4 13 -5 2

int main(){
	
	int n;
	cin >> n;
	int a[n], sum[n], max = INT_MIN;
		
	for(int i = 0; i < n; i++){
		sum[i] = INT_MIN;
		cin >> a[i];
		
		sum[i] = a[i];		
		if(i > 0 && sum[i - 1] >= 0) sum[i] += sum[i - 1];
		
		if(sum[i] > max) max = sum[i];
	}
	
	cout << max;
	return 0;
}
