#include<iostream>
#include<utility>
#include<memory>




// 这里是因为move将原来的变量失效并且将该变的使用权转移到新的变量上，结果都是将转化为右值

int main()
{
    auto important = std::make_shared<int>(1);
    auto add = [v1 = 1,v2 = std::move(important)](int x,int y) ->int {return x+y+v1+(*v2);};
    // std::cout << *important << std::endl;
    std::cout << add(3,4) << std::endl;


// 表达式的返回值若不做要求的话会根据变量自行改变，若规定了变量则会按照指定的结果返回
    auto add2 = [](auto x,auto y) ->double{
        return x + y;
    };
    std::cout << add2(1,2) << std::endl;
    std::cout << add2(1.1,2.2) << std::endl;

    return 0;
}