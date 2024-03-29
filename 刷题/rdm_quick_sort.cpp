#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

class Solution {
    private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for(int j = l; j <= r - 1 ; ++j) {
            if(nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int randomized_partition(vector<int>& nums, int l, int r) {
        // 这里我们随机选择一个数
        int i = rand() % (r - l + 1)  + l;
        swap(nums[r], nums[i]);
        return partition(nums, l ,r);
    }

    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if(l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

    public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};