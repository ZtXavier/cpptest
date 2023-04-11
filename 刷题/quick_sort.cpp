#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int quick_sort(vector<int>& Arr, int left, int right) {
    // 这里先定义哨兵节点
    int index = left;
    int l = left;
    int r = right;
    // 这里使用了填坑法,将哨兵节点保存起来然后
    // 每次不必交换,直接覆盖坑位,最后需要把坑位
    // 还原到哨兵节点处
    int dig = Arr[index];
    while(l < r) {
        while(l < r && Arr[r] >= dig) {
            r--;
        }
        if(l < r) {
            Arr[l]  = Arr[r];
            l++;
        }
        while(l < r && Arr[l] <= dig) {
            l++;
        }
        if(l < r) {
            Arr[r] = Arr[l];
            r--;
        }   
    }
    // 一定哟注意
    Arr[l] = dig;
    return l;
}



void Quick_Sort(vector<int> &Arr, int left, int right) {
    if(left >= right) {
        return ;
    }
    int new_index = quick_sort(Arr, left, right);
    Quick_Sort(Arr, left, new_index - 1);
    Quick_Sort(Arr, new_index + 1, right);
}



int main() {

    vector<int> vt = {5,43,6,785,4,6,7,8,5,4,1};
    for(int i = 0;i < vt.size(); ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;

    Quick_Sort(vt,0,vt.size() - 1);

        for(int i = 0;i < vt.size(); ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;
}