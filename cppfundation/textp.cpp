#include<iostream>
#include<cctype>
using namespace std;

// int op(int a,int b)
// {
//     return 0;
// }
// float op(double a,int b)
// {
//     return 0.0;
// }


int main(void){
    int row;
    cout << "请输入行数: ";
    cin >> row;
    for(int i = 0;i < row; i++){
        for(int j = 0;j < row -i -1;j++){
            cout << " ";
        }
        for(int j = 0;j < 2 * i + 1;j++){
            cout << "$";
        }
        cout << endl;
    }
    return 0;
}