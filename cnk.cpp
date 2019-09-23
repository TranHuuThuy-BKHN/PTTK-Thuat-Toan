#include<iostream>
#include<cmath>

using namespace std;

int main(){
	
	int T, k;
	double n, m; 
	cin >> T;
	double *res = new double[T];
	
	for(int i = 0; i < T; i++){
		
		cin >> n >> k >> m;
		
		if(k == 0 || k == n){
			res[i] = 1 - m * floor(1 / m);
			continue;
		}else if(k == 1 || k == n - 1){
			res[i] = n - m * floor(n / m) ;
			continue;
		}
		
		if(k > n/2) k = n - k;
		
		
		double *tu = new double[k];
		int *mau = new int[k];
		
		
		for(int j = 0; j < k; j++){
			tu[j] = n - k + j + 1;
			mau[j] = j + 1;
		}
	
		
		for(int j = k-1; j > - 1 ; j--){
			for(int h = 0; h < k; h++){
				if(tu[h] == floor(tu[h] / mau[j]) * mau[j]){
					tu[h] /= mau[j];
					break;
				}
			}
		}
		
		double s = 1.0;
		for(int j = 0; j < k; j++){
			tu[j] = tu[j] - m * floor(tu[j] / m);
			if(tu[j] == 0){
				s = 0;
				break;
			}
			s = s * tu[j];
			s = s - m * floor(s/m);
		}	
		
		res[i]	= s;
		
	}
	
	if(T > 0){
		for(int i = 0; i < T - 1; i++)
			printf("%.0lf\n", res[i]);
									
		printf("%.0lf", res[T - 1]);
	}
	
	return 0;
}
