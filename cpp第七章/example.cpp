#include<iostream>
#include<cctype>
#include<string>

class BaseClass
{
    public:
    std::string  name;

    BaseClass(std::string name);
    ~BaseClass();

    void dosomething();
};

class Subclass : public BaseClass
{
    public:
    Subclass(std::string name);
    ~Subclass();
    void dosomething(int num);
};

BaseClass::BaseClass(std::string name)
{
    std::cout << " 进入基类构造器...\n ";
    std::cout << " 开始在基类构造器中做事...\n ";
    std::cout << std::endl;
}

BaseClass::~BaseClass()
{
    std::cout << " 进入基类析构器...\n ";
    std::cout << " 开始在基类析构器中做事...\n ";
    std::cout << std::endl;
}

void BaseClass::dosomething(void)
{
    std::cout << name << "正在做一些事情..." << std::endl;
}

void Subclass::dosomething(int num)
{
    BaseClass::dosomething();
    std::cout << "我又做了" << num << "件事情\n" << std::endl;
}

Subclass::Subclass(std::string name) : BaseClass(name)
{
    std::cout << " 进入子类构造器...\n ";
    std::cout << " 开始在子类构造器中做事...\n ";
    this->name = name;
    std::cout << std::endl;
}

Subclass::~Subclass()
{
    std::cout << " 进入子类析构器...\n ";
    std::cout << " 开始在子类析构器中做事...\n ";
    std::cout << std::endl;
}


int main(void)
{
    Subclass sub("ada");            //这也是一种初始化的方式
    //sub.dosomething();            //使用错误，被子类覆盖掉了，所以调用该方法必须用子类的方法，可以在子类的方法中再调用基类的方法
    sub.dosomething(15);
    std::cout << "结束\n" << std::endl;
    return 0;
}