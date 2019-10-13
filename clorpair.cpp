#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;


struct Point2D{
	int x, y;
	int index;
};

double distance2D(Point2D A, Point2D B){
	return sqrt((A.x-B.x) * (A.x-B.x) + (A.y-B.y) * (A.y-B.y)) ;
}

Point2D* Greedy(Point2D *C , int L , int R){
	double Min = 10000000000 ;
	Point2D *p = new Point2D[2];
	
	for( int i = L ; i <= R ; i++ ){
		for( int j = i+1 ; j <= R ; j++ ){
				double x = distance2D(C[i] , C[j]) ;
				if(Min > x){
					Min = x ;
					p[0] = C[i];
					p[1] = C[j];
				}
		}
	}
	return p;
}

void Tim_dai(Point2D *C , double d, int &Mid_L , int &Mid_R , int L , int R){
	int Mid = (L + R) / 2 ;
	for( int i = L ; i <= R ; i++ )
		if( C[i].x >= C[Mid].x - d ){
			Mid_L = i ; break ;
		}
	for( int i = R ; i >= L ; i-- )
		if( C[i].x <= C[Mid].x + d ){
			Mid_R = i ; break ;
		}
}

bool TrongHinhVuong( Point2D a , Point2D A , double d){
	return A.x-d <= a.x && A.x+d >= a.x && A.y+d >= a.y && A.y-d <= a.y ;
}

bool cmp_x(const Point2D &a , const Point2D &b ){
	return a.x < b.x ;
}


Point2D* distance2D_mid(Point2D *C , int L , int R , double d){
	double Min = 10000000000;
	Point2D *p = new Point2D[2];
	
	for( int i = L ; i <= R ; i++ ){//Tuy hai vong for nhung thoi gian chi la O(n) do moi Point2D chi kiem tra voi
		for( int j = L ; j < i ; j++ ){                                                    //toi da 6 Point2D khac
			if(TrongHinhVuong(C[j] , C[i] , d ) ){
					double x = distance2D(C[i] , C[j]) ;
					if(Min > x){
						Min = x ;
						p[0] = C[i];
						p[1] = C[j];
					}
			}
		}
	}
	return p;
}

Point2D* distance2D_min(Point2D *C , int L , int R){
	if(R - L <= 2 ) return Greedy(C, L, R);//neu co it hon 4 Point2D thi ta vet can
	
	int Mid = (L + R) / 2 , Mid_L , Mid_R ;
	
	Point2D *d_left = distance2D_min(C,L,Mid);
	Point2D *d_right = distance2D_min(C,Mid+1,R);//tim ra khoang cach o nua trai va phai
	
	Point2D *min_left_right;
	
	distance2D(d_left[0], d_left[1]) >= distance2D(d_right[0], d_right[1]) 
	? min_left_right = d_right : min_left_right = d_left;	
	
	double d = distance2D(min_left_right[0], min_left_right[1]);
	
	Tim_dai(C , d  , Mid_L , Mid_R , L , R );//tim dai o giua
	
	Point2D *d_mid = distance2D_mid(C , Mid_L , Mid_R , d ) ;//tim khoang cach nho nhat o nua giua
	
	return d >= distance2D(d_mid[0], d_mid[1]) ? d_mid : min_left_right;
	
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
	
	Point2D *res = distance2D_min(C, 0, n - 1);
	
	if(res[0].index > res[1].index){
		printf("%d %d %.6lf",res[1].index, res[0].index, distance2D(res[1], res[0]));
	}else printf("%d %d %.6lf",res[0].index, res[1].index, distance2D(res[1], res[0]));

	return 0 ;
}
// 5
// 0 0
// 0 1
// 100 45
// 2 3
// 9 9
