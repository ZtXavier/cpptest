#include<iostream>

class person1
{
public:
    void showperson1()
    {
        std::cout << "person1 show" << std::endl;
    }
};


class person2
{
public:
    void showperson2()
    {
        std::cout << "person2 show" << std::endl;
    }
};

template<class T>
class Myclass
{
    public:
        T obj;
        //类模板中的成员函数
        void func1()
        {
            obj.showperson1();  //该成员函数不会报错，是因为在运行前不会调用该函数
        }
        void func2()
        {
            obj.showperson2();
        }

};


int main(void)
{
    Myclass<person1> p;
    p.func1();
    // p.func2();  错误，只有调person1的函数可以通过，因为是showperson2没有在person1中
    return 0;
}