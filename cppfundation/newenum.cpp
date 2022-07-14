#include<iostream>
#include<type_traits>
#include<tuple>
enum class new_enum : unsigned int 
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};


//显示的拿取enum中的元素
template<typename T>
std::ostream& operator<< (typename std::enable_if<std::is_enum<T>::value,std::ostream>::type& stream,const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}


// 下面是两个简单的例子
template<class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type 
is_odd(T i){return bool(i%2);}

template<class T,class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T i) {return !bool(i%2);}

int main()
{
    std::cout << new_enum::value3 << std::endl; 
    // short i = 1;
    // std::cout << std::boolalpha;
    // std::cout << "i is odd: " << is_odd(i) << std::endl;
    // std::cout << "i is even: " << is_even(i) << std::endl;
    return 0;
}