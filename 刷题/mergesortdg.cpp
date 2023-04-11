#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

void Merge_sort(vector<int>& Arr, int front, int mid, int end) {
    vector<int> leftSubarr(Arr.begin() + front, Arr.begin() + mid + 1);
    vector<int> rightSubarr(Arr.begin() + mid + 1, Arr.begin() + end + 1);
    int indleft = 0;
    int indright = 0;
    // 这里是为了从小到大排序,所以为了防止访问越界所以给要排序
    // 的数组最后插入两个int的最大值
    leftSubarr.insert(leftSubarr.end(), numeric_limits<int>::max());
    rightSubarr.insert(rightSubarr.end(), numeric_limits<int>::max());

    for(int i = front; i <= end; ++i) {
        if(leftSubarr[indleft] < rightSubarr[indright]) {
            Arr[i] = leftSubarr[indleft];
            indleft++;
        } else {
            Arr[i] = rightSubarr[indright];
            indright++;
        }
    }
}

void MergeSort(vector<int>& Arr, int front, int end) {
    if(front >= end) {
        return;
    }
    int mid = (front + end) / 2;
    MergeSort(Arr, front, mid);
    MergeSort(Arr, mid + 1, end);
    Merge_sort(Arr, front, mid, end);
}



int main() {
    vector<int> vt = {4,3,2,5,67,4,6,4,5,6,2};
    int num = vt.size();
    for(int i = 0;i < num; ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;

    MergeSort(vt, 0, num - 1);

    for(int i = 0;i < num; ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;
}