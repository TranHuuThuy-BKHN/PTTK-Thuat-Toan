#include<iostream>

using namespace std;

int main(){
	string num1, num2, zero = "0", one = "1", anwser;
	
	cout << "Enter number 1:"; getline(cin, num1);
	cout << "Enter number 2:"; getline(cin, num2);
	
	int l1 = num1.length(), l2 = num2.length(), carry_out = 0;
	
	if(l1 > l2){
		for(int i = 0; i < l1 - l2; i++)
			num2 = zero + num2;
	}else if(l1 < l2){
		for(int i = 0; i < l2 - l1; i++)
			num1 = zero + num1;
	}
	
	for(int i = num1.length() - 1; i > - 1; i--){
		
		int s = num1[i] + num2[i] - 96 + carry_out;
		if(s < 10){
			anwser = (char)(s + 48) + anwser;
			carry_out = 0;
		}else{
			anwser = (char)(s % 10 + 48) + anwser;
			carry_out = 1;	
		} 
	}
	
	if(carry_out == 1) anwser = one + anwser;
	
	cout << "Sum of 2 numbers :" << anwser;
	
	return 0;
}
