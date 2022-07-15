#include<iostream>
#include<vector>

int main()
{
    std::vector<int> v;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    v.push_back(4);
    v.push_back(5);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    // 因为vector在自动扩容后无法自动将没有用的内存还给操作系统
    //  所以需要手动归还
    v.clear();
    v.shrink_to_fit(); 
    // v.resize(0); //不归还内存，只改变数组空间大小
    // v.reserve(10);  // 只改变容量
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    return 0;
}