#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


struct Course{
	int duration;
	int index;
};

bool cmp_x(const Course &c1 , const Course &c2 ){
	return c1.duration > c2.duration ;
}

int main(){
	
	int n, m;
	cin >> n >> m;
	int A[n][n];
	Course course[n];
	vector<int> teacher_of_course[n];

	vector<int> teacher[m];
	
	int load_of_teacher[m];
	
	for(int i = 0; i < m; i++)
		load_of_teacher[i] = 0;
	
	// doc du lieu	
	for(int i = 0; i < n; i++){
		cin >> course[i].duration;
		course[i].index = i;
	}
	
	for(int i = 0; i < n; i++){
		int num_of_teacher;
		cin >> num_of_teacher;
		
		for(int j = 0; j < num_of_teacher; j++){
			int temp;
			cin >> temp;
			teacher_of_course[i].push_back(temp - 1);
		}
	}
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> A[i][j];
		}
	}	
	//=========================
	
	//sap xep theo duration
	sort(course, course + n, cmp_x);
	
	//duyet cac khoa hoc
	for(int i = 0; i < n; i++){
		//duyet cac teacher day khoa hoc do
		//tim giao vien dang co thoi luong tiet it nhat
		//giao vien dang duoc phan chia ko co mon xung dot
		int load_max = INT_MAX, iTeacher = -1;
		
		for(int j = 0; j < teacher_of_course[course[i].index].size(); j++){
			//kiem tra xem giao vien co day mon xung dot hay khong
			int t = teacher_of_course[course[i].index][j];	
			bool check = true;
			
			for(int k = 0; k < teacher[t].size(); k++){
				int h = teacher[t][k];
				
				if(A[course[i].index][h] == 1){
					check = false;
					break;
				}
			}
			if(check && load_max > load_of_teacher[t]){
				load_max = load_of_teacher[t];
				iTeacher = t;
			}
			
		}
		
		if(iTeacher != -1){
			load_of_teacher[iTeacher] += course[i].duration;
			teacher[iTeacher].push_back(course[i].index);
		}else{
			cout << -1;
			return 0;
		}
	}
	
	int load_max = INT_MIN;	
	for(int i = 0; i < m; i++){
		if(load_max < load_of_teacher[i]) load_max = load_of_teacher[i];
	}
	
	cout << load_max;
	return 0;
}
