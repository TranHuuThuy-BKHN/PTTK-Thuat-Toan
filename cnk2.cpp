#include<iostream>
#include<cmath>

using namespace std;

double gcd_extension(int k, double m){
    double q, r, a1 = 1, a2 = 0, b1 = 0, b2 = 1;
    double a = k, b = m;
    double t1 = a1, t2 = b1;

    q = (double)floorl(a / b);
    r = a - b * q;

    while(r != 0){
        a = b;
        b = r;
        t1 = a1; t2 = b1;
        a1 = a2; b1 = b2;
        a2 = t1 - q*a2;
        b2 = t2 - q*b2;
        q = (double)floorl(a / b);
        r = a - b * q;
    }
    return (a2 < 0 ? a2 + m : a2);
}

//k < n, m --> theo yêu cầu đề bài và m là số nguyên tố
double mode_cnk(double n, int k, double m){
    double tu_mau[2 * k];
    double res = 1;

    for(int i = 0; i < k; i++){
        tu_mau[i] = n - k + 1 + i;
        tu_mau[i + k] = gcd_extension(i + 1, m);
    }

    for(int i = 0; i < 2 * k; i++){
        tu_mau[i] -= (double)floorl(tu_mau[i] / m) * m;
        res *= tu_mau[i];
        res -= (double)floorl(res / m) * m;
    }

    return res;
}

int main(){
    int T; cin >> T;
    double res[T];
    double n, m;
    int k;
    
    for(int i = 0; i < T; i++){
        cin >> n;
        cin >> k;
        cin >> m;
        res[i] = mode_cnk(n, k, m);
    }

    for(int i = 0; i < T; i++){
        printf("%.0lf\n", res[i]);
    }
    return 0;
}