#include<iostream>
#include<vector>
#include<numeric>

class Solution {
public:
    // n 是节点的数量
    int n = 1005; 
    // 初始化一个数组来存放并查集
    std::vector<int> v1;

public:
    int find(int u);
    void init();
    void join(int u,int v);
    bool same(int u,int v);


};

// 并查集需要有一个函数来进行寻根过程
// 这里是使用递归寻找
int Solution::find(int u) {
    // 刚开始初始化都是u == v1[u]
    return u == v1[u] ? u : v1[u] = find(v1[u]);
}

// 初始化并查集
void Solution::init() {
    v1 = std::vector<int>(n);
    std::iota(v1.begin(), v1.end(), 0);
}

// 判断u和v是否找到一个根
bool Solution::same(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u这条边加入并查集
void Solution::join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v){
        return;
    }
    // 如果不同的话构建并查集,使用一个数组模拟一个map
    v1[v] = u;
}

// ToDo测试
int main() {

    return 0;
}