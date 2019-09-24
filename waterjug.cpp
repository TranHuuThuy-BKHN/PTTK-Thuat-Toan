#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
	int x;
	int y;
	int height;
};

//tra ve null neu nhu n ko co trong visited
Node* find(vector<Node*> visited, Node* n){
	for(int i = 0; i < visited.size(); i++){
		if(visited[i]->x == n->x && visited[i]->y == n->y){
			return visited[i];
		}
	}
	return NULL;
}


int bfs_waterjug(int a, int b, int c){
	int min_height = INT_MAX;
	
	vector<Node*> visited;
	queue<Node*> queue_node;
	
	Node *roof = new Node;
	roof->x = 0; roof->y = 0; roof->height = 0;
	
	queue_node.push(roof);
	
	while(!queue_node.empty()){
		
		Node *head = queue_node.front();
		queue_node.pop();
		
		visited.push_back(head); //them vao danh sach da tham
		
		int x = head->x, y = head->y;
	
		if((x == c || y == c) && min_height > head->height){
			min_height = head->height;
		}
		
		int xs[] = {a, 0, 0, x + y - b, x, x, x + y, a},
			ys[] = {y, y, x + y, b, 0, b, 0, x + y - a};
			
		for(int i = 0; i < 8; i++){
			if(xs[i] > -1 && xs[i] <= a && ys[i] > - 1 && ys[i] <= b){
				Node *temp = new Node;
				temp->x = xs[i]; temp->y = ys[i]; temp->height = 0;
				Node *n = find(visited, temp);	
							
				if(n == NULL){
					temp->height = head->height + 1;
					queue_node.push(temp);
	
				}else if(n->height > head->height + 1){
					n->height = head->height + 1;
					queue_node.push(n);
				}
			}
		}
		
	}
	return min_height == INT_MAX ? -1 : min_height;
}

int main(){
	cout << bfs_waterjug(3, 8, 2);
	return 0;
}
