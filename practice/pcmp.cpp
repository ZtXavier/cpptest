#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// sort函数在使用时需要注意,第三个参数使用来传入一个普通的函数
// 而在类中如果要传入一个普通的成员函数会报错,因为成员函数会将自己的this指针传入
// 造成参数不匹配,所以要传入一个static的成员函数避免该问题


int main() {
    vector<int> vt;
    for(int i = 0; i < 10; ++i) {
        vt.push_back(i);
    }
    sort(vt.begin(),vt.end(),[](int a, int b){return a > b;});
    for(int i = 0; i < vt.size(); i++) {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;

}