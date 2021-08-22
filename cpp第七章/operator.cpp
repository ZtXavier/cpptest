#include<cctype>
#include<string>
#include<iostream>

class Baseclass
{
    public:
        Baseclass();
        Baseclass(int *p);
        Baseclass(const Baseclass &p);
        ~Baseclass();

        Baseclass &operator=(const Baseclass &p);
        void print();
    private:
        int *pth;
};

Baseclass::Baseclass()
{
    std::cout << "进入Baseclass int 构造器" << std::endl;
    pth = new int;
    std::cout << "离开Baseclass int 构造器" << std::endl;
}

Baseclass::Baseclass(int *p)
{
    std::cout << "进入Baseclass int 构造器" << std::endl;
    pth = p;
    std::cout << "离开Baseclass int 构造器" << std::endl;
}


Baseclass::Baseclass(const Baseclass &p)
{
    std::cout << "进入副本构造器" << std::endl;
    *this = p;
    std::cout << "离开副本构造器" << std::endl;
}

Baseclass::~Baseclass()
{
    std::cout << "进入析构器" << std::endl;
    delete pth;
    std::cout << "离开析构器" << std::endl;
}

Baseclass &Baseclass::operator=(const Baseclass &rth)
{
    std::cout << "进入等号重载器" << std::endl;
    if(this != &rth)
    {
        delete pth;
        pth = (new int);
        *pth = *rth.pth;
    }
    else
    {
        std::cout << "对象相同，不作处理" << std::endl;
    }
    std::cout << "离开等号重载器" << std::endl;
    return *this;
}

void Baseclass::print()
{
    std::cout << pth << std::endl;
}

int main(void)
{
    Baseclass base1(new int(1));
    Baseclass base2(new int(2));
    base1 = base2;

    base1.print();
    base2.print();

    std::cout << "\n" << std::endl;

    Baseclass base3(new int(3));
    Baseclass base4;
    base4 = base3;
    base3.print();
    base4.print();

    std::cout << "\n" << std::endl;

    Baseclass base5(new int(5));
    base5 = base5;
    base5.print();
    return 0;
}