#include<iostream>
#include<string>
#include<vector>

void reference(int &v)
{
    std::cout << "左值" << std::endl;
}

void reference(int &&v)
{
    std::cout << "右值" << std::endl;
}

template<typename T>
void pass(T&& v)
{
    std::cout << "普通传参" << std::endl;
    reference(v);
}








int main()
{
    // std::string str= "h";
    // std::vector<std::string> v;

    // v.push_back(str);
    // std::cout << "str: " << str << std::endl;
    // v.push_back(std::move(str));
    // std::cout << "str: " << str << std::endl;



    /* 
        根据推导规则来看
        模板函数中的T&& 不一定进行右引用，根据传入的参数值来判断
        下边是推导规则
        函数形参类型 实参参数类型 推导后函数形参类型
            T&                  左引用              T&
            T&                  右引用              T&
            T&&                左引用              T&
            T&&                右引用              T&&
     */
    std::cout << "传递右值" << std::endl;
    pass(1);
    std::cout << "传递左值" << std::endl;
    int l = 1;
    pass(l);
    return 0;
}