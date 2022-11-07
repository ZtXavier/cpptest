#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

bool cmp(int a, int b) {
    return a < b;
}

bool dealwithbefore(std::vector<int> &num, std::vector<int> &A, std::vector<int> &signal) {
    int n = signal.size();
    int p = 0;
    int flag = 0;
    for(int i = 0; i < signal.size(); ++i) {
        if(signal[i] > 0) {
            p = i;
            flag = 1;
            num[i] = A[signal[i] - 1];
            break;
        }    
    }

    for(int i = p+1;i < n;i++) {
        num[i] = A[A.size() - 1];
    }

    if(flag) {
        return true;
    }
    return false;
}




int main() {
    int num;
    int nums;
    std::cout << "请输入n:" << std::endl;
    std::cin >> num;
    std::cout << "请输入A 表内的个数" << std::endl;
    std::cin >> nums;
    std::vector<int> A;
    for(int i = 0;i < nums;i++) {
        int tmp;
        std::cin >> tmp;
        A.push_back(tmp);
    }
    // 进行排序 
    // sort(A.begin(),A.end(),cmp);

    int n = num;
    std::vector<int> weishu;
    while(n > 0) {
        weishu.push_back(n % 10);
        n /= 10;
    }
    int ws = weishu.size();
   std::vector<int> signal;
    std::vector<int> ret;

    int point = 0;
    int flag = 0;
    for(int i = weishu.size() - 1; i >= 0; --i) {
        for(int j = 0;j < A.size();++j) {
            if((A[j] > weishu[i]) && (i == ws - 1) && (j == 0)) {
                flag = 1;
                break;
            } else if((A[j] > weishu[i]) && (j == 0)) {
                if(dealwithbefore(ret, A, signal)) {   
                    point = i;
                } else {
                    flag = 1;
                }
                break;
            } else if(A[j] > weishu[i]) {
                ret.push_back(A[j - 1]);
                point = i;
                break;
            } else if(A[j] == weishu[i]) {
                signal.push_back(j);
                ret.push_back(A[j]);
            }
        }
        if(!flag) {
            break;
        }
    }

    if(flag) {
        std::cout << "not have the num" << std::endl;
        return 0;
    }
    for(int i = ws - point + 1; i < ws; i++) {
        ret.push_back(A[A.size() - 1]);
    }
    int r = 0;
    for(int i = 0;i < ret.size(); ++i) {
        r = r * 10 + ret[i];
    }

     std::cout << r << std::endl;
    return 0;
}