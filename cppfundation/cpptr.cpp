#include<iostream>
#include<memory>

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}


int main()
{
    auto pointer = std::make_shared<int>(10);
    foo(pointer);
    std::cout << *pointer << std::endl;

    auto pointer2 = pointer;
    auto pointer3 = pointer;

    //该方式不会增加引用计数
    int *p = pointer.get(); 
    std::cout << "pointer.use_count: " << pointer.use_count() << std::endl;
    pointer.reset();
    std::cout << "one: " << pointer.use_count() << std::endl;
    std::cout << "two: " << pointer2.use_count() << std::endl;
    std::cout << "three: " << pointer3.use_count() << std::endl;
    int *a = pointer2.get();
    std::cout << *a <<std::endl;
    //reset 后的智能指正对象已经将重置，若重置参数为空则delete
    return 0;
}

