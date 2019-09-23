#include<iostream>

using namespace std;

void quickSort(int a[], int iLeft, int iRight){
	if(iLeft >= iRight) return;
	
	int X = a[iLeft], i = iLeft + 1, j = iRight;
	
	while(i <= j){
		if(a[i] >= X && a[j] < X){
			swap(a[i], a[j]);
			i++; j--;
		}else if(a[i] < X) i++;
		else j--;
	}
	swap(a[iLeft], a[j]);
	quickSort(a, iLeft, j - 1);
	quickSort(a, j + 1, iRight);
}

int main(){
	int n; cin >> n;
	int *a = new int[n];
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	quickSort(a, 0, n - 1);
	for(int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1];
	
	
	return 0;
}
