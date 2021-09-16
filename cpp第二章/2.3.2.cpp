#include<iostream>
using namespace std;
int main(void){
    int i = 33;
    int a = 0;
    int &r = i;
    // &r = a;  //引用不可再修改，因为其实质为 int *const r = &a;
    int *p = &r;
    cout << *p << " " << r << " " << i << endl;
    *p = 0;    //对p所指的对象赋值
    cout << *p << " " << r << " "<< i <<endl;
    return 0;
    /*虽然未初始化的指针会指向该指针中的一个不确定值作为地址
    然后操纵该内存地址中存放的的为内容，所以对其赋值不报错，但是不建议这样做*/
}