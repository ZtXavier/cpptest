#include<cctype>
#include<iostream>
#include<string>
class op
{
    public:
        op(int real,int num);
        ~op();
        op operator + (op d);
        op operator - (op d);
        op operator / (op d);
        op operator * (op d);
        void print();
    private:
        int real;
        int num;
        friend std::ostream &operator<<(std::ostream& os,op c);
};


op ::op(int real,int num)
{
    if(num < 0)
    {
        this->real = -real;
        this->num = -num;
    }else
    {
        this->real = real;
        this->num = num;
    }
    int a = abs(this->real);
    int b = abs(this->num);
    while(b)
    {
        int t = a % b;    //辗转相除求最大公约数
        a = b;
        b = t;
    }
    this->real /= a;
    this->num /= a;
}

op ::~op()
{

}

op op ::operator+(op d)
{
    int e,f;
    e = this->real * d.num + this->num * d.real;
    f = this->num * d.num;
    return op(e,f);
}

op op ::operator-(op d)
{
    int e,f;
    e = this->real * d.num - this->num * d.real;
    f = this->num * d.num;
    return op(e,f);
}


op op ::operator/(op d)
{
    int e,f;
    e = this->real * d.num;
    f = this->num * d.real;
    return op(e,f);
}

op op ::operator*(op d)
{
    int e,f;
    e = this->real * d.real;
    f = this->num * d.num;
    return op(e,f);
}

void op::print()
{
    if(real%num == 0)
    std::cout << real/num;
    else
    std::cout << real << "/" <<num ;
}

std::ostream& operator<<(std::ostream& os,op c);

std::ostream& operator<<(std::ostream& os,op c)
{
    os << c.real << "/" << c.num;
    return os;
}

int main(void)
{
    /*  op c1(2,6),c2(3,4); */
    // op c1 = op(2,6);
    // op c2 = op(3,4);
    // c2.print();
    // op ret = c1 + c2;   //等价于 op ret(变量) =  op(1,3);
    // std::cout << " = ";
    // ret.print();
    // std::cout << "\n" << std::endl;

    // c1.print();
    // std::cout << " - " ;
    // c2.print();
    // ret = c1 - c2;
    // std::cout << " = ";
    // ret.print();
    // std::cout << "\n" << std::endl;

    // c1.print();
    // std::cout << " * " ;
    // c2.print();
    // ret = c1 * c2;
    // std::cout << " = ";
    // ret.print();
    // std::cout << "\n" << std::endl;

    // c1.print();
    // std::cout << " / " ;
    // c2.print();
    // ret = c1 / c2;
    // std::cout << " = ";
    // ret.print();
    // std::cout << "\n" << std::endl;
    /* 将<<来重载，为其定义新的函数 */
    op c1 = op(2,6);
    op c2 = op(3,4);
    std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;
    std::cout << c1 << " - " << c2 << " = " << c1-c2 << std::endl;
    std::cout << c1 << " * " << c2 << " = " << c1*c2 << std::endl;
    std::cout << c1 << " / " << c2 << " = " << c1/c2 << std::endl;
    return 0;
}