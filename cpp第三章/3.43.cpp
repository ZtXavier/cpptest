#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::string;
using std::vector;
int main(void){
    int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // for(const int (&c1)[4] : ia)  //若改为(*c1)[4]则会导致下一个for语句对int*内部遍历，也就是对常量遍历
    // for(int c : c1)
    // cout << c << " ";
    // cout << endl;


    // int (*cl)[4] = ia;
    // for(int i = 0;i < 12;i++)
    // cout << (*cl)[i] << " ";  //*cl[i]结合会先和[i]结合再结合*，所以*cl[i]为指针的数组(里面存的为指针)，(*cl)[i]为指向cl里面常量的数组(二维数组)
    // cout << endl;

    for(int (*p)[4] = begin(ia);p != end(ia);p++)
    for(int *q = begin(*p); q != end(*p); q++)
    cout << *q << " ";
    cout << endl;
    return 0;
}