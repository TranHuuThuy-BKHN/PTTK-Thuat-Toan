#include<iostream>

using namespace std;


struct Data{
	int th;
	int r;
};

Data* divide(int n, int k){
	Data *d = new Data;
	double temp = k;
	int v = 1;
	for(int i = 0; i < n; i++){
		temp /= (n - i);
		v *= (i + 1);
	}
	
	if(temp >= 1){
		d->th = k / v;
		d->r = k % v;
	}else{
		d->th = 0;
		d->r = k;
	}
	return d;
}

void permutationlist(bool *visited, int n, int k){
	
	if(divide(n, k)->th != 0){
		cout << -1;
		return;
	}
	
	int t = n - 1, r = k, c = 1;
	do{
		Data *d = divide(t, r);	
		int i = d->th + 1;
		c = 1;
		r = d->r;
		
		for(int j = 0; j < n; j++){
			if(!visited[j]){
				if(c == i){
					cout << j+1 << " ";
					visited[j] = true;
					break;	
				}
				c++;
			}
		}
		t--;	
	}while(t > -1);
	
}


int main(){
	
	int n, k;
	cin >> n >> k;
	bool *visited = new bool[n];
	
	for(int i = 0; i < n; i++)
		visited[i] = false;
		
	permutationlist(visited, n, k - 1);
	
	return 0;
}
