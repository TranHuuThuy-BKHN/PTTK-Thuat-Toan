#include<iostream>
#define N 15
using namespace std;

// 3
// 0 5 10 10 
// 6 0 2 9
// 5 9 0 6
// 1 7 4 0

int tsp(int i, int S, int n, int **c, int **memory){
	if(S == (1<<n) - 1){
		return c[i][0];
	}

	int res = 1<<31 - 1;
	if(memory[i][S] != -1){
		return memory[i][S];
	}

	for(int j = 0; j < n; j++){
		if((S>>j) & 1) continue;
		
		res = min(res, c[i][j] + tsp(j, S | (1<<j), n, c, memory));
	}
	
	memory[i][S] = res;
	return memory[i][S];
}


int main(){

	int n; cin >> n;
	n++;
	int **c;
	int **memory;

	memory = new int*[n];
	c = new int*[n];

	for(int i = 0; i < n; i++){
		memory[i] = new int[1<<n];
		for(int j = 0; j < 1<<n; j++){
			memory[i][j] = -1;
		}
	}
	
	for(int i = 0; i < n; i++){
		c[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin >> c[i][j]; 
		}
	}

	cout << tsp(0, 1<<0, n, c, memory);
	return 0;
}

