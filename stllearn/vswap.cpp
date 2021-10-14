#include<iostream>
#include<vector>

void test01()
{
    std::vector<int> v1;
    for(int i = 0;i < 100000;i++)
    {
        v1.push_back(i);
    }

    std::cout << v1.capacity() << std::endl;
    std::cout << v1.size() << std::endl;

    std::cout << " changed " << std::endl;
    v1.resize(3);            //直接改变容器大小会导致容量不变而造成空间浪费

    std::cout << v1.capacity() << std::endl;
    std::cout << v1.size() << std::endl;


    //我们可以巧用swap函数来进行容器大小的放缩
    //我们可以利用匿名对象的性质来进行容器大小的互换
    //匿名对象作为pure rvalue 不可以作为引用，当为匿名对象时，匿名对象创建后就会被系统回收
    std::vector<int> (v1).swap(v1);
    std::cout << v1.capacity() << std::endl;
    std::cout << v1.size() << std::endl;

}



int main(void)
{
    test01();
    return 0;
}