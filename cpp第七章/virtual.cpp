#include<cctype>
#include<iostream>
#include<string>

class person
{
    public:
        person(std::string name);
        ~person();
        void sleep();
        virtual void eat();
    protected:
        std::string name;
};

person::person(std::string name)
{
    std::cout << "你好！我叫" << name << std::endl;
    this->name = name;
}

void person::sleep()
{
    std::cout << name << "开始睡觉" << std::endl;
}

void person::eat()
{
    std::cout << name << "开始吃饭" << std::endl;
}

person::~person()
{
    std::cout << "基类退出..." << std::endl;
}

class men : public person
{
    public:
        men(std::string name);
        ~men();
        void eat();
};

men::men(std::string name) : person(name)
{

}

men::~men()
{
     std::cout << name << "结束了一生..." << std::endl;
}

void men::eat()
{
    person::eat();
    std::cout << name <<"吃了十碗饭!" << std::endl;
}

class Women : public person
{
    public:
        Women(std::string name);
        ~Women();
        void eat();
};

Women::Women(std::string name) : person(name)
{

}

void Women::eat()
{
    person::eat();
    std::cout << name <<"吃了五碗饭!" << std::endl;
}

Women::~Women()
{
    std::cout << name << "结束了一生..." << std::endl;
}

int main(void)
{
    // men m("张三");
    // Women wm("如花");              //一般调用方法
    person *m = new men("张三");
    // men *m = new men("张三");      //用new来进行空间开创
    person *fm = new Women("如花");
    m->eat();                         //因为是用基类来定义一个指针变量，为了效率会只编译基类定义的函数而不是将子类所覆盖的一同编译，所以需要visual
    m->sleep();
    fm->eat();
    fm->sleep();
    delete m;
    delete fm;
    return 0;

}