#include<iostream>
#include"simplearr.hpp"
#include<vector>
#include<string>


class person
{
public:
    person(){}                             //注意，在该类的变量要默认定义的话必须要有默认构造函数
    person(int age,std::string name)
    {
        this->name = name;
        this->age = age;
    }
    void showdata()
    {
        std::cout << this->name << " " << this->age << std::endl;
    }
private:
    int age;
    std::string name;
};

void test2()
{
    person p1(1010,"ll");
    person p2(101,"wl");
    person p3(10,"hl");
    person p4(1,"sl");
    Arrary<person> arr(4);
    arr.Push_back(p1);
    arr.Push_back(p2);
    arr.Push_back(p3);
    arr.Push_back(p4);
    for(int i = 0;i < arr._Size();i++)
    {
        arr[i].showdata();
    }
}


// void test()
// {
//     Arrary<int> arr(5);

//     std::cout << arr._Size() << std::endl;
//     std::cout << arr._Capacity() << std::endl;
//     for(int i = 0;i < arr._Capacity();i++)
//     {
//         arr[i] = i;
//     }
//     for(int i = 0;i < arr._Capacity();i++)
//     {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << arr._Size() << std::endl;

//     Arrary<int> arr1(arr);
//     arr1 = arr;
//     std::cout << arr1._Size() << std::endl;
//     std::cout << arr1._Capacity() << std::endl;

//     Arrary<int> arr2(4);
//     arr2.Push_back(0);
//     arr2.Push_back(2);
//     arr2.Push_back(3);
//     arr2.Push_back(9);
//     for(int i = 0;i < arr2._Size();i++)
//     {
//         std::cout << arr2[i] << " ";
//     }
//     std::cout << std::endl;
//     arr2.Pop_arr();
//     for(int i = 0;i < arr2._Size();i++)
//     {
//         std::cout << arr2[i] << " ";
//     }
//     std::cout << std::endl;

// }



int main(void)
{
    // test();
    test2();
    return 0;
}
