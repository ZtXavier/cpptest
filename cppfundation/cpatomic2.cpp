#include<iostream>
#include<atomic>


/* 并非所有的类型都能提供原子操作，这是因为原子操作的可行性
取决于 CPU 的架构以及所实例化的类型结构是否满足该架构对内
存对齐条件的要求，因而我们总是可以通过 std::atomic<T>::is_lock_free 
来检查该原子类型是否需支持原子操作 
*/


struct A
{
    float x;
    int y;
    long long z;
};

int main()
{
    std::atomic<int> a;
    std::cout << std::boolalpha << a.is_lock_free() << std::endl;
    return 0;
}