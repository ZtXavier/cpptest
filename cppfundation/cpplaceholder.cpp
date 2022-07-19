#include<iostream>
#include<string>
#include<functional>

void goodbye(const std::string &s)
{
    std::cout << "Goodbye"  << std::endl;
}

class Object
{
public:
    int hello(const std::string &s)
    {
        std::cout << "hello" << std::endl;
        return 1;
    }
};

int main()
{
    using namespace std::placeholders;
    using Exepfun = std::function<void(const std::string&)>;
    Object obj;
    std::string str("world");
    Exepfun f = std::bind(&Object::hello,&obj,_1);
    f(str);
    // 如果是相同数据类型的函数可以绑定给一个相同参数类型的类方法
    f = std::bind(&goodbye,std::placeholders::_1);
    f(str);
    auto lambda = [](std::string pre,char o,int rep,std::string post){
        std::cout << pre;
        while(rep-- > 0)
        {
            std::cout << 0;
        }
        std::cout << post << std::endl;
    };
    // 可以使用function来包一个lambda表达式来进行访问
    std::function<void(std::string,char,int,std::string)>g  =  std::bind(&decltype(lambda)::operator(),&lambda,_1,_2,_3,"hello");
    //  std::function<void(std::string,char,int,std::string)>g  =  std::bind(&decltype(lambda)::operator(),&lambda,_4,_2,_3,_1);
    // 如果某些占位符所对应的参数的数据类型相同,则他们之间可以进行替换
    g("G",'o','o'-'g',"dwadw");
    // 如果占位符不再是默认的话则被指定的占位符将替换掉函数中定义的参数
    return 0;
}

