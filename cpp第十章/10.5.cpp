#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<list>


//equal 可以比较不同容器的值
int main()
{
    // std::vector<std::string> v1 = {"wdawd","lllooo"};
    // std::list<const char*> ls = {"wdawd","lllooo"};
    // std::vector<const char*> v1 = {"wdawd","lllooo"};
    // std::list<const char*> ls = {"wdawd","lllooo"};
    const char * a = "abc";
    const char * b = "ooo";
    std::vector<const char *> v1;
    std::list <const char *> l1;
    v1.push_back(a);
    l1.push_back(b);
    std::cout << equal(v1.begin(),v1.end(),l1.begin()) << std::endl;
    return 0;
}