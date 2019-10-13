#include<iostream>

using namespace std;

void permutation(unsigned int *a, int n){
	int i = 0, j = n - 1;
	
	//tim vi tri i can thay the
	for(i = n - 1; i > 0; i--){
		if(a[i] > a[i - 1]) break;
	}
	
	if(i == 0){
		cout << -1;
		return;
	}else i--;
	
	for(j = n - 1; j > i; j--){
		if(a[i] < a[j]) break;
	}
	
	if(j == i) j = n - 1;
	
	swap(a[i], a[j]);
	
	for(int h = i + 1; h < (n + 1 + i) / 2; h++){
		swap(a[h], a[n - h + i]);
	}
	
	for(int h = 0; h < n; h++)
		cout << a[h] << " ";
}


int main(){
	int n;
	cin >> n;
	unsigned int *a = new unsigned int[n];
	
	for(int i = 0; i < n ; i++)
		cin >> a[i];
	
	permutation(a, n);
	
	return 0;
}
