#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        int step;
        string res;
        for(int i = 7;i >=0;i--)
        {
            step = (num >> (i * 4)) & 0xf;    //每四位进行一个与计算
            if(res.length() > 0 || step > 0)  //这里是为了将正整数的高位为零的部分筛选掉
            {
                char ch = step < 10 ? (char)(step + '0') : (char)( step - 10 + 'a');//该部分用字母替换数字很巧妙
                res.push_back(ch);
            }
        }
        for(auto i: res )
        {
            cout << i << endl;
        }
        cout << res << endl;
        return res;
    }
};



int main()
{
    Solution s;
    s.toHex(26);
    return 0;
}