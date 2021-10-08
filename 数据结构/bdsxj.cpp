#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define MAX 20

class caltion
{
public:
    caltion()
    {
        // std::cout << "进入析构函数" << std::endl;
        top1 = top2 = -1;
        this->numarr = new double[MAX];
        this->sign = new char[MAX];
        this->s1 = new char[MAX];
    }
    //计算表达式结果
    double resultnum(std::string &in);
    //返回后缀缀表达式
    char *frontres(std::string &in);
    //子表达式计算
    double soncaltion(double a,char op,double b,double &result);
    //判断优先级
    int priority(char s);

private:
    int top1,top2;
    double *numarr;
    char  *sign;
    char  *s1;
};

double caltion::soncaltion(double a,char op,double b,double &result)
{
    switch(op)
    {
        case '+':
        result = a + b;
        break;
        case '-':
        result = a - b;
        break;
        case '*':
        result = a * b;
        break;
        case '/':
        if(b == 0)
        return 0;
        result = a / b;
        break;
        default:
        std::cout << "输入错误符号"  << std::endl;
        return 0;
    }
    return 1;
}

double caltion::resultnum(std::string &in)
{
    double result;
    int num = 0;
    int flag = 1;
    for(int i = 0;i < in.size();i++)
    {
        if(in[i] >= '0' && in[i] <= '9')
        {
            flag = 0;
            num = num*10 + (in[i]-'0');
            if(i == in.size() - 1)
            {
                numarr[++(this->top1)] = num;
            }
            else if((i < in.size() - 1) && in[i+1] >= '0' && in[i+1] <= '9')
            {
                continue;
            }
        }
        else
        {
            if(flag == 0)
            {
                numarr[++(this->top1)] = num;
                num = 0;
                flag = 1;
            }
            if(in[i] == '(')
            {
                if(in[i - 1] >= '0' && in[i -1] <= '9')
                {
                    this->sign[++(this->top2)] = '*';
                }
                this->sign[++(this->top2)] = in[i];
            }
            else if((in[i] == '*' || in[i] == '/') && (sign[this->top2] == '+' || sign[this->top2] == '-' || sign[this->top2] == '(' || this->top2 == -1))
            {
                this->sign[++(this->top2)] = in[i];
            }
            else if((in[i] == '+' || in[i] == '-') && (this->top2 == -1 || sign[this->top2] == '('))
            {
                this->sign[++(this->top2)] = in[i];
            }
            else if(in[i] == ')')  //如果是右括号则直到匹配到左括号为止
            {
                while(sign[top2] != '(')
                {
                    if(this->top2 == -1)
                    {
                        std::cout << "无法匹配到括号" << std::endl;
                        return 0;
                    }
                    double a,b;
                    char op;
                    b = numarr[top1--];
                    a = numarr[top1--];
                    op = sign[top2--];
                    if(soncaltion(a,op,b,result) == 0)
                    {
                        std::cout << "除数不可以为零,错误" << std::endl;
                        return -1;
                    }
                    numarr[++top1] = result;
                }
                sign[--top2];
            }
            else if((in[i] == '+' || in[i] == '-') && (sign[this->top2] == '+' || sign[this->top2] == '-' || sign[this->top2] == '*' || sign[this->top2] == '/'))   //如果是乘号或者除号为栈顶且入栈的为加号或减号则计算优先级高的
            {
                    double a,b;
                    char op;
                    b = numarr[top1--];
                    a = numarr[top1--];
                    op = sign[top2--];
                    if(soncaltion(a,op,b,result) == 0)
                    {
                        std::cout << "除数不可以为零,错误" << std::endl;
                        return -1;
                    }
                    if(sign[top2] == '-')
                    {
                        numarr[++top1] = (-result);
                        sign[top2] = '+';
                        sign[++top2] = in[i];
                    }
                    else
                    {
                        numarr[++top1] = result;
                        sign[++top2] = in[i];            //在将栈顶优先级高的出栈后再将该符号入栈
                    }
            }
            else if((in[i] == '*' || in[i] == '/') && (sign[this->top2] == '*' || sign[this->top2] == '/'))
            {
                    double a,b;
                    char op;
                    b = numarr[top1--];
                    a = numarr[top1--];
                    op = sign[top2--];
                    if(soncaltion(a,op,b,result) == 0)
                    {
                        std::cout << "除数不可以为零,错误" << std::endl;
                        return -1;
                    }
                    if(sign[top2] == '-')
                    {
                        numarr[++top1] = (-result);
                        sign[top2] = '+';
                        sign[++top2] = in[i];
                    }
                    else
                    {
                        numarr[++top1] = result;
                        sign[++top2] = in[i];            //在将栈顶优先级高的出栈后再将该符号入栈
                    }
            }
        }
    }

    while(top2 != -1)
    {
        double a,b;
        char op;
        b = numarr[top1--];
        a = numarr[top1--];
        op = sign[top2--];
        if(soncaltion(a,op,b,result) == 0)
        {
            std::cout << "除数不可以为零,错误" << std::endl;
            return -1;
        }
        numarr[++top1] = result;
    }
    return numarr[top1];
}


int caltion::priority(char s)
{
    if(s == '+' || s == '-')
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

char *caltion::frontres(std::string &in)    //中缀转后缀
{
    char ch[MAX];
    char *res;
    res = (char*)malloc(sizeof(char)*MAX);
    int top1,top2;
    top1 = top2 = -1;
    for(int i = 0;i < in.size();i++)
    {
        if(in[i] >= '0' && in[i] <= '9')
        {
            res[++top1] = in[i];
        }
        else if(in[i] == '(')
        {
            ch[++top2] = in[i];
        }
        else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
        {
            if(top2 == -1 || ch[top2] == '(' || priority(in[i]) > priority(ch[top2]))
            {
                ch[++top2] = in[i];
            }
            else
            {
                res[++top1] = ch[top2--];
            }
        }
        else if(in[i] == ')')
        {
            while(ch[top2] != '(')
            {
                res[++top1] = ch[top2--];
            }
            top2--;
        }
    }
    while(top2 != -1)
    {
        res[++top1] = ch[top2--];
    }
    res[++top1] = '\0';
    return res;
}
int main(void)
{

    caltion cal;
    std::string s1;
    std::cout << "请输入表达式：" << std::endl;
    std::cin >> s1;
    std::cout << "结果为：" << cal.resultnum(s1) << std::endl;
    char *res;
    res = cal.frontres(s1);
    for(int i = 0;res[i] != '\0';i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}