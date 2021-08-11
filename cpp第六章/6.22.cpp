#include<cctype>
#include<iostream>
#include<vector>
using namespace std;
using std::string;
int compare_(int *&a,int *&p){   //要交换指针必须来引用交换所指的地址
    int *temp = NULL;
    temp = a;
    a = p;
    p = temp;
    return 0;
}


int main(void){
    int i = 5;
    int a = 10;
    int *p = &a;
    int *j = &i;
    cout << *p << " " << *j << endl;
    compare_(j,p);
    cout << *p << " " << *j << endl;
    return 0;
}