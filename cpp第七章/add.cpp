#include<iostream>
#include<cctype>
#include<string>
class addnum
{
    public:
        addnum();
        addnum(float real,float fake);
        ~addnum();
        addnum *add(addnum *info);
    // private:
        float real;
        float fake;
};

addnum::addnum()
{
    this->real = 0;
    this->fake = 0;
}

addnum::addnum(float real,float fake)
{
    this->real = real;
    this->fake = fake;
}

addnum *addnum::add(addnum *info)
{
    addnum *c;
    c->real = this->real + info->real;
    c->fake = this->fake + info->fake;
    return c;
}

addnum::~addnum()
{

}

int main(void)
{
    float real,fake;
    std::cout << "请输入第一个负数:" << std::endl;
    std::cin >> real;
    std::cin >> fake;
    addnum *info1 = new addnum(real,fake);
    std::cout << "请输入第二个负数:" << std::endl;
    std::cin >> real;
    std::cin >> fake;
    addnum *info2 = new addnum(real,fake);
    std::cout << info1->real << "," << info1->fake << "i + " << info2->real << "," << info2->fake;
    addnum *info3 = new addnum();
    info3 = info2->add(info1);
    std::cout << "i = " << info3->real << "," << info3->fake << "i" <<std::endl;
    info1->~addnum();
    info2->~addnum();
    info3->~addnum();
    delete info1;
    delete info2;
    delete info3;
    return 0;
}