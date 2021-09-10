#include<iostream>
#include<cctype>
#include<vector>

class NoDefault
{
    public:
    NoDefault(int x):a(x) {}
    void print() { std::cout << this->a << std::endl; }
    private:
    int a;
};

int main(void)
{
    std::vector<NoDefault> ver(10,1);
    std::vector<NoDefault>::iterator it = ver.begin(); //it存放的是每个NoDefault类型的地址
    for(;it != ver.end();it++)
    {
        it->print();
    }
    return 0;
}