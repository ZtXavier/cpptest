#include<cctype>
#include<iostream>
#include<string>
class person
{
    public:
        person(std::string name);
    protected:
        std::string name;
};

class men : virtual public person
{
    public:
        men(std::string name,std::string work);
        void introduct();
    protected:
        std::string work;
};

class women : virtual public person
{
    public:
        women(std::string name,std::string love);
        void introduct();
    protected:
        std::string love;
};

class doubwm : public men,public women
{
    public:
        doubwm(std::string name,std::string work,std::string love);
        void introduct();
    // protected:
    //     std::string name;
};

person::person(std::string name)
{
    this->name = name;
}

men::men(std::string name,std::string work) : person(name)
{

    this->work = work;
}

void men::introduct()
{
    std::cout << "大家好，我是" << name <<",我是" << work << "的" << std::endl;
}

women::women(std::string name,std::string love) : person(name)
{

    this->love = love;
}

void women::introduct()
{
    std::cout << "大家好，我是" << name <<",我的爱好是" << love << std::endl;
}

doubwm::doubwm(std::string name,std::string work,std::string love) : men(name,work),women(name,love),person(name)
{
     //this->name = name;
}


void doubwm::introduct()
{
    std::cout << "大家好，我是" << /* women::name */ name << ",我是" << work << "的,并且我的爱好是" << love << std::endl;  //注意，多继承重名的要（1）指明继承的父类，否则会出现二异性（2）用虚继承的方法
}
int main(void)
{
    women w("小红","唱歌");
    men  m("小明","阿里");
    doubwm dou("小贝","腾讯","唱歌");
    w.introduct();
    m.introduct();
    dou.introduct();
    return 0;
}