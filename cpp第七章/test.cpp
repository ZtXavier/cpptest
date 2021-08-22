#include<cctype>
#include<iostream>
#include<string>
using namespace std;

class example
{
    int Test;
public:
    example(int x):Test(x) //带参数构造函数
    {
        cout << "constructor\n";
    }

    example(const example & ex) //拷贝构造函数
    {
        Test = ex.Test;
        cout << "copy constructor\n";
    }

    example &operator = (const example &ex)//赋值函数(赋值运算符重载) 返回该类的引用
    {
        cout << "= operator\n";
        Test = ex.Test;
        return *this;                    //解引用，将返回的是exaple类型的类
    }

    void Func(example ex)
    {

    }
};

int main()
{
    example a(2);
    example b(3);
    b = a;
    example c = a;
    b.Func(a);

    return 0;
}
