#include<iostream>
#include<tuple>
#include<variant>



auto get_student(int id)
{
    if(id == 0)
    {
        return std::make_tuple(3.8,'A',"Adw");
    }
    if(id == 1)
    {
        return std::make_tuple(2.9,'C',"Bob");
    }
    if(id == 2)
    {
        return std::make_tuple(2.5,'D',"Jerry");
    }
    return std::make_tuple(0.0,'D',"Larry");
}




// 解决问題的方案
// template<size_t n,typename... T>
// constexpr std::variant<T...>_tuple_index(const std::tuple<T...>& tp1,size_t i)
// {
//     if constexpr (n >= sizeof...(T))
//     {
//         throw std::out_of_range("over limit");
//     }
//     if(n == i)
//     {
//         return std::variant<T...>
//         {
//             std::in_place_index<n>,std::get<n>(tp1);
//         };
//     }
// }
// template<typename... T>
// constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tp1,size_t i)
// {
//     return _tuple_index<0>(tp1,i);
// }

// template<typename T0,typename ...Ts>
// std::ostream & operator << (std::ostream& s,std::variant<T,Ts...> const & v)
// {
//     std::visit([&](auto && x){s << x;},v);
//     return s;
// } 








int main()
{
    auto student = get_student(0);
    std::cout << "ID 0: "
    << "GPA: " << std::get<0>(student) << ", "
    << "garde: " << std::get<1>(student) << ", "
    << "name: " << std::get<2> (student) << '\n';

    std::tuple<std::string,double,double,int> t("123",4.5,6.7,9);
    // 当一个元组中有多个相同数据类型的元素，使用这种方式会预编译报错
    std::cout << std::get<double>(t) << std::endl;
    std::cout << std::get<std::string>(t) << std::endl;
    std::cout << std::get<1>(t) << std::endl;
    std::cout << std::get<2>(t) << std::endl;
    std::cout << std::get<3>(t) << std::endl;
    // 如何解决这种传参过程与运行时赋值冲突的问题
    // int indx = 2;
    // std::cout << std::get<indx>(t) << std::endl;



    return 0;
}