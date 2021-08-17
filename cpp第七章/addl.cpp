#include<cctype>
#include<iostream>
#include<string>
class op
{
    public:
        op();
        op(float real,float fake);
        ~op();
        op operator + (op &d);
        op operator - (op &d);
        op operator / (op &d);
        op operator * (op &d);
        void print();

    private:
        float real;
        float fake;
};

op ::op()
{
    this->real = 0;
    this->fake = 0;
}

op ::op(float real,float fake)
{
    this->real = real;
    this->fake = fake;
}

op ::~op()
{
    
}

op op ::operator+(op &d)
{
    op c;
    c.real = this->real + d.real;
    c.fake = this->fake + d.fake;
    return c;
}

op op ::operator-(op &d)
{
    op c;
    c.real = this->real - d.real;
    c.fake = this->fake - d.fake;
    return c;
}


op op ::operator/(op &d)
{
    op c;
    c.real = this->real / d.real;
    c.fake = this->fake / d.fake;
    return c;
}

op op ::operator*(op &d)
{
    op c;
    c.real = this->real * d.real;
    c.fake = this->fake * d.fake;
    return c;
}

void op::print()
{
    std::cout << "(" << real << "," << fake << "i)" << std::endl;
}

int main(void)
{
    op c1(1,3),c2(2,-4),c3;
    c3 = c1 + c2;
    std::cout << "c1 = ";
    c1.print();
    std::cout << "c2 = ";
    c2.print();
    std::cout << "c1 + c2 = ";
    c3.print();
    return 0;
}