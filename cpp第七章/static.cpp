#include<iostream>
#include<cctype>
#include<string>

class Animal
{
    public:
        Animal(std::string name);
        ~Animal();
        static int count();
    protected:
        std::string name;
    private:
        static int cout;
};

int Animal::cout;  //开创内存,并为其初始化

Animal::Animal(std::string name)
{
    this->name = name;
    cout++;
    std::cout << name << "出生啦!\n" << std::endl;
}

Animal::~Animal()
{
    std::cout << name << "挂了..." << std::endl;
    cout--;
}

int Animal::count()
{
    return cout;
}

class cat : public Animal
{
    public:
        cat(std::string name);
};

cat::cat(std::string name) : Animal(name)
{

}

class mouse : public Animal
{
    public:
        mouse(std::string name);
};

mouse::mouse(std::string name) : Animal(name)
{

}

int main(void)
{
    cat c("Tom");
    mouse m("Jerry");
    std::cout << "新诞生了" << Animal::count() << "只动物" << std::endl;
    {
    cat c1("tom");
    mouse m1("jerry");
    std::cout << "还剩下存活的" << Animal::count() << "只动物" << std::endl;
    }   //c++的特点用法，在括号里面的会先析构完成变量的改变
    std::cout << "还剩下存活的" << Animal::count() << "只动物" << std::endl;
    return 0;
}