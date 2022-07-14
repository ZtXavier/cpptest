#include<iostream>

// 递归来解包来遍历所有模板参数
template<typename T0>
void printf1(T0 value)
{
    std::cout << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value,Ts... args)
{
    std::cout << value << std::endl;
    printf1(args...);
}


// 递归遍历的方法2
template<typename T0,typename ... T>
void printf2(T0 t0,T ...t)
{
    std::cout << t0  << std::endl;
    if constexpr(sizeof ...(t) > 0)
    {
        printf2(t...);
    } 
}


// 有条件终止的递归代码 使用initializer_list 和lambda表达式
template<typename T,typename ...Ts>
auto printf3(T value ,Ts...  args)
{
    std::cout << value << std::endl;
    (void)std::initializer_list<T> {([&args]{std::cout << args << std::endl;}(),value)...};
}

template<typename ... T>
auto sum(T ... t)
{
    return (t + ...);
}


int main()
{
    // printf1(1,2,"123",1.1);
    // printf2(2,3,4,1.1,"dawfdwa");
    // printf3(1,2,3,4,5.7,"dwadwggg");
    std::cout << sum(1,2,3,4,5,6) << std::endl;
    return 0;
}
