
/*
Cho 1 số nguyên dương n. Đưa ra xâu nhị phân độ dài n thứ k trong thứ tự từ điển mà không có i số 0 liên tiếp.

Input
Dòng đầu ghi 3 số nguyên dương n,k,i≤10^4 cách nhau bởi dấu cách

Output
Ghi ra xâu nhị phân độ dài n thứ k mà không có i số 0 liên tiếp trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách. 
Nếu không tồn tại thì ghi ra -1.


input
6 4 2

output
0 1 1 0 1 0 

input
2 3 10

output
1 0 
*/
#include<iostream>
#include<stack>

using namespace std;

struct Node{
    string binary_str;
    int num_of_end_zeros;
};

int main(){
    //sử dụng stack để làm bài easy này
    //chuỗi nhị phân thỏa mãn, theo thứ tự từ điển sẽ được stack thăm lần lượt
    int n = 0, k, i, c = 0;
    cin >> n >> k >> i;
    Node result;

    //một vài trường hợp cơ bản nhận thấy ngay kết quả
    if(i == 1){
        for(int j = 0; j < n; j++)
            cout << '1' << " ";
        return 0;
    }

    Node root = {"", 0};
    stack<Node> stack_node;
    stack_node.push(root);

    string bi_str;
    int nZeros, l;

    while(!stack_node.empty()){
        Node head = stack_node.top();
        stack_node.pop();

        bi_str = head.binary_str;
        nZeros = head.num_of_end_zeros;
        l = bi_str.length();
        //điều kiện dừng
        if(l == n){
            c++;
            result = head;
            if(c == k) break;
            else continue;
        }  
        Node rNode = {bi_str + '1', 0};
        //phải thêm rNode trước để đảm bảo thứ tự theo từ điển
        stack_node.push(rNode);

        if(nZeros < i - 1){
            Node lNode = {bi_str + '0', nZeros + 1};
                stack_node.push(lNode);
        }
    }

    for(int i = 0; i < result.binary_str.length(); i++){
        cout << result.binary_str[i] << " ";
    }

    return 0;
}