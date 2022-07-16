#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> count = {0};

int main()
{
    // int a = 0;
    // int flag = 0;

    // std::thread t1([&]()
    // {
    //     while(flag != 1);
    //     int b = a;
    //     std::cout << "b = " << b << std::endl;
    // });

    // std::thread t2([&](){
    //     a = 5;
    //     flag = 1;
    // });
    // t1.join();
    // t2.join();
    std::thread t1([](){
        count.fetch_add(1);
    });
    std::thread t2([](){
        count++;
        count += 1;
    });
    t1.join();
    t2.join();
    std::cout << count << std::endl;
    return 0;
}