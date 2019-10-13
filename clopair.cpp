#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

/*
Cho N điểm trên mặt phẳng, hãy tìm một cặp điểm với khoảng cách euclid nhỏ nhất giữa chúng. 
Biết rằng không có hai điểm nào trùng nhau và có duy nhất một cặt có khoảng cách nhỏ nhất.

Input
Dòng đầu tiên chứa một số nguyên N (2≤N≤50000). 
N dòng tiếp theo mỗi dòng chứa hai số nguyên là tọa độ X và Y của một điểm.
Giá trị tuyệt đối của X, Y không vượt quá 10^6.

Output
Ghi ra 3 số abc, trong đó a,b (a<b) là các chỉ số của cặp điểm tìm được trong dữ liệu vào (chỉ số bắt đầu từ 0) 
và c là khoảng cách giữa chúng. Làm tròn c đến 6 chữ số sau dấu phẩy động.

*/

struct Point2D{
	int x, y;
	int index;
};

struct Edge{
    Point2D p1;
    Point2D p2;
};

double distance2D(Point2D A, Point2D B){
	return sqrt((A.x-B.x) * (A.x-B.x) + (A.y-B.y) * (A.y-B.y)) ;
}

double distance2D(Edge e){
	return distance2D(e.p1, e.p2);
}

Edge Greedy(Point2D *C , int L , int R){
	double min = 1000000000000;
	Edge e;	
	for(int i = L ; i <= R ; i++ ){
		for(int j = i+1 ; j <= R ; j++){
			double x = distance2D(C[i] , C[j]) ;
			if(min > x){
				min = x ;
				e.p1 = C[i];
				e.p2 = C[j];
			}
		}
	}
	return e;
}

void Tim_dai(Point2D *C , double d, int &Mid_L , int &Mid_R , int L , int R){
	int Mid = (L + R) / 2 ;
	for(int i = Mid - 1 ; i >= L ; i--)
		if( C[i].x < C[Mid].x - d ){
			Mid_L = i + 1 ; break ;
	    }

	for(int i = Mid + 1; i <= R ; i++)
		if( C[i].x > C[Mid].x + d ){
			Mid_R = i - 1 ; break ;
		}
}

bool isInSquare(Point2D a , Point2D A , double d){
	return A.x-d <= a.x && A.x+d >= a.x && A.y+d >= a.y && A.y-d <= a.y ;
}

bool cmp_x(const Point2D &a , const Point2D &b ){
	return a.x < b.x ;
}


Edge distance2D_mid(Point2D *C , int L , int R , double d){
	double min = 1000000000000;
    int mid = (L + R) / 2;
	Edge e;

    for(int i = L; i < mid; i++){
        for(int j = mid + 1; j <= R; j++){
            if(isInSquare(C[j] , C[i] , d )){
				double x = distance2D(C[i] , C[j]) ;
				if(min > x){
					min = x ;
					e.p1 = C[i];
					e.p2 = C[j];
				}
			}
        }
    }
	return e;
}

Edge distance2D_min(Point2D *C , int L , int R){
	if(R - L <= 2 ) return Greedy(C, L, R);//neu co it hon 4 Point2D thi ta vet can
	
	int Mid = (L + R) / 2 , Mid_L , Mid_R;
	
	Edge e_left = distance2D_min(C,L,Mid);
	Edge e_right = distance2D_min(C,Mid+1,R);//tim ra khoang cach o nua trai va phai
	Edge e_minLR = distance2D(e_left) >= distance2D(e_right) ? e_right : e_left;	

	double d = distance2D(e_minLR);
	
	Tim_dai(C , d  , Mid_L , Mid_R , L , R );//tim dai o giua
	
	Edge e_mid = distance2D_mid(C , Mid_L , Mid_R , d) ;//tim khoang cach nho nhat o nua giua
	
	return d >= distance2D(e_mid) ? e_mid : e_minLR;
}

int main(){
	int n ;
	cin >> n ;
	
	Point2D *C = new Point2D[n];
	
	for(int i = 0; i < n; i++){
		cin >> C[i].x >> C[i].y;
		C[i].index = i;
	}
	
	sort(C,C+n,cmp_x);
	
	Edge e = distance2D_min(C, 0, n - 1);
	
	if(e.p1.index > e.p2.index){
		printf("%d %d %.6lf",e.p2.index, e.p1.index, distance2D(e));
	}else printf("%d %d %.6lf",e.p1.index, e.p2.index, distance2D(e));

	return 0 ;
}
// 5
// 0 0
// 0 1
// 100 45
// 2 3
// 9 9
