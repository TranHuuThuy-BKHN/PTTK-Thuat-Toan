#include<iostream>
#include<Stack>
#define N 1000


using namespace std;

struct Diem{
	int x;
	int y;
};

int main(){
	int m, n;
	
	cin >> m >> n;
	
	char *M[m];
	int *visited[m];
	
	for(int i = 0; i < m; i++){
		M[i] = new char[n];
		//doc tung hang ma tran		
		fflush(stdin);
		cin.getline(M[i], n + 1);
		
		visited[i] = new int[n];
		for(int j = 0; j < n; j++){
			visited[i][j] = 0;
		}		
	}
	
	int max_dao = 0, max_area = 0;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			
			if(M[i][j] == '1' && visited[i][j] == 0){
				max_dao++;
				int area = 1;
				
				Diem *root = new Diem; root->x = i; root->y = j; 
				stack<Diem* > stack_Diem;
				stack_Diem.push(root);
				
				while(!stack_Diem.empty()){
					Diem *p = stack_Diem.top();
					stack_Diem.pop();
					
					int x = p->x, y = p->y;
					
					visited[x][y] = 1;
					
					int xs[] = {x, x, x + 1, x - 1};
					int ys[] = {y - 1, y + 1, y, y};
					
					for(int k = 0; k < 4; k++){
						if(xs[k] > -1 && xs[k] < m && ys[k] > -1 && ys[k] < n && visited[xs[k]][ys[k]] == 0 && M[xs[k]][ys[k]] == '1'){
							Diem *next = new Diem;
							next->x = xs[k];
							next->y = ys[k];
							
							stack_Diem.push(next);
							visited[xs[k]][ys[k]] = 1;
							area++;
						}
					}
				}
				
				if(area > max_area) max_area = area;				
			}
		}
	}
	
	cout << max_dao << endl << max_area;
	
	return 0;
}



