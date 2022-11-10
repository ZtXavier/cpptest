#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> answer;
    int base, count, maxCount;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            // 这个是开一个base大小元素都为0的vector
            answer = vector<int> (base);
        }
    }
    
};

int main() {
    Solution s;
    s.update(1);
    s.update(1);
    s.update(2);
    s.update(2);
    s.update(2);
    for(int i = 0;i < s.answer.size();++i)
    std::cout << s.answer[i] << std::endl;
    return 0;
}
