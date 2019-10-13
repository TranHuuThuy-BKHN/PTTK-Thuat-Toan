#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = n - 1; i > -1; i--){
        if(s[i] == '0'){

            s[i] = '1';
            for(int j = i + 1; j < n; j++)
                s[j] = '0';
            
            cout << s;
            
            return 0;
        }
    }
    cout << -1;

    return 0;
}