#include<iostream>
#define N 3

using namespace std;

int get_index_sys(char open_sys[], char c){
	for(int i = 0; i < N; i++)
		if(c == open_sys[i])
			return i;
	return -1;
}


int main(){

	int T;cin >> T;
	int *res = new int[T];
	
	string parentheses_expression;
	char open_sys[N] = {'(', '[', '{'};
	char close_sys[N] = {')', ']', '}'};
	
	for(int i = 0; i < T; i++){
		fflush(stdin);
		getline(cin, parentheses_expression);
		char temp[parentheses_expression.length()];
		int j = 0, k;
		
		for(int m = 0 ; m < parentheses_expression.length(); m++){
			temp[j++] = parentheses_expression[m];
			//neu la dong ngoac, va trc no la mo ngoac tuong ung thi giam j di 2
			k = get_index_sys(close_sys, parentheses_expression[m]);
			
			if(k != -1 && (j - 2 > -1 && open_sys[k] == temp[j - 2]))
				j -= 2;
		}
		
		j == 0 ? res[i] = 1 : res[i] = 0;
	}
	
	for(int i = 0; i < T - 1; i++)
		cout << res[i] << endl;
	cout << res[T - 1];
	
	return 0;
}

