#include<iostream>
#include<numeric>
#include<algorithm>
#include<vector>

template<typename T>
void merge_sort(T arr[], int len) {
    T *a = arr;
    // 在迭代的过程中新开一个数组来存放每次迭代的排序结果
    T *b = new T[len];
    for(int seg = 1; seg < len; seg += seg) {
        // 这里为什么seg += seg?
        // 回答:这里是因为归并的时间复杂度是log(n)
        for(int start = 0; start < len; start += seg + seg) {
            int low = start;
            int mid = std::min(start + seg, len);
            int high =std::min(start + seg + seg, len);
            int k = low;
            int start1 = low;
            int end1 = mid;
            int start2 = mid;
            int end2 = high;
            while(start1 < end1 && start2 < end2) {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while(start1 < end1) {
                b[k++] = a[start1++];
            }
            while(start2 < end2) {
                b[k++] = a[start2++];
            }
        }

        //  在这里进行每次进行导换,很重要的点,也很巧妙
        T *tmp = a;
        a = b;
        b = tmp;
    }
    if(a != arr) {
        for(int i = 0; i < len; ++i) {
            b[i] = a[i];
        }
        b = a;
    }
    delete[] b;
}


int main () {
    int vt[] = {1,5,34,5,7,8,6,5,34,9};
    int num = sizeof(vt) / sizeof(int);
    for(int i = 0; i < num; i++) {
        std::cout << vt[i] << " ";
    }
    std::cout << std::endl;
    merge_sort<int>(vt,num);
    for(int i = 0; i < num; i++) {
        std::cout << vt[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

