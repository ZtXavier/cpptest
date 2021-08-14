#include<iostream>
#include<cctype>
#include<string>

class Lover
{
    public:
        std::string thing;
        Lover(std::string name);
        ~Lover();
        void kiss(Lover *lover);
        void askdosomething(Lover *lover,std::string thing);
    protected:
        std::string name;
        friend class other;
};

Lover::Lover(std::string name)
{
    this->name = name;
}

Lover::~Lover()
{

}

void Lover::kiss(Lover *lover)
{
    std::cout << name << "亲了"<< lover->name << "一口" << std::endl;
}

void Lover::askdosomething(Lover *lover,std::string thing)
{
    std::cout << name << "要求" << lover->name << thing << std::endl;
}

class bf :public Lover
{
    public:
        bf(std::string name);
};

bf::bf(std::string name) : Lover(name)
{

}

class gf :public Lover
{
    public:
        gf(std::string name);
};

gf::gf(std::string name) : Lover(name)
{

}

class other
{
    public:
    std::string name;
    other(std::string name);
    void kiss(Lover *lover);
};

other::other(std::string name)
{
    this->name = name;
}

void other::kiss(Lover *lover)
{
    std::cout << name << "偷偷亲了" << lover->name << "一口" << std::endl;
}

int main(void)
{
    bf byf("小明");
    gf grf("小红");
    byf.askdosomething(&grf,"早睡");
    byf.kiss(&grf);
    other person("路人甲");
    person.kiss(&grf);
    return 0;
}