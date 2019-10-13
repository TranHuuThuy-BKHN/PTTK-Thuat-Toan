#include<iostream>
#include<queue>

using namespace std;

/*
A Maze is represented by a 0-1 matrix aN×M in which ai,j = 1 means cell (i,j) is an obstacle, ai,j = 0 means cell (i,j) is free. 
From a free cell, we can go up, down, left, or right to an adjacent free cell. 
Compute the minimal number of steps to escape from a Maze from a given cell (i0,j0) within the Maze.

input
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1
*/

struct Point{
	int x; 
	int y;
	int height;
};

int main(){
	int m, n, x0, y0, min_steps = -1;

	cin >> m >> n >> x0 >> y0;
	x0--; y0--;
	char M[m][n];
	bool visited[m][n];

	//đọc dữ liệu ma trận bài toán
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> M[i][j];
			visited[i][j] = false;
		}
	}

	//========================
	Point p;
	p.x = x0; p.y = y0; p.height = 0;

	//khởi tạo hàng đợi
	//điểm được duyệt đầu tiên trong hàng đợi là nối ra có height chính là kết quả bài toán
	queue<Point> queue_point;
	queue_point.push(p);

	while(!queue_point.empty()){
		//lấy phần tử đầu tiên khỏi hàng đợi
		Point head = queue_point.front();
		queue_point.pop();
		//=================================
		int x = head.x, y = head.y;
		visited[x][y] = true;  //đánh dấu đã đi qua điểm này

		if(x == 0 || y == 0 || x == m - 1 || y == n - 1){
			min_steps = head.height;
			break;
		}

		int xs[] = {x, x, x - 1, x + 1};
		int ys[] = {y - 1, y + 1, y, y};
		
		for(int i = 0; i < 4; i++){
			if(xs[i] > -1 && xs[i] < m && ys[i] > -1 && ys[i] < n
						  && !visited[xs[i]][ys[i]] && M[xs[i]][ys[i]] == '0'){
			
				Point next;
				next.x = xs[i]; next.y = ys[i]; next.height = head.height + 1;

				queue_point.push(next); //thêm vào hàng đợi
			}
		}
	}

	cout << min_steps + 1;
	return 0;
}