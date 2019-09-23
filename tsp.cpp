#include<iostream>

using namespace std;

int min(int c[], bool visited[], int n){
	int min = INT_MAX, i = -1;
	for(int j = 0; j < n; j++){
		if(!visited[j] && min > c[j] && c[j] != 0){
			min = c[j];
			i = j;
		}
	}
	return i;
}

int main(){

	int n, distances_min = 0, 
		pre_city = 0, now_city = 0,
		next_city; cin >> n;
	n = n + 1;
	int c[n][n];
	bool visited[n];
	
	visited[0] = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> c[i][j];
	}
	
	while(now_city != -1){
		next_city = min(c[now_city], visited, n);
		if(next_city != -1){
			distances_min += c[now_city][next_city];
			visited[next_city] = true;
		}
		pre_city = now_city;
		now_city = next_city;
	
	}
	
	cout << distances_min + c[pre_city][0];
	
	return 0;
}

