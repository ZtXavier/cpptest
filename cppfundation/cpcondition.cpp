#include<queue>
#include<chrono>
#include<mutex>
#include<thread>
#include<iostream>
#include<condition_variable>

int main()
{
    std::queue<int> produced_nums;
    std::mutex mtx;
    // 条件变量
    std::condition_variable cv;
    bool notified = false;
    auto producer = [&](){
        // 在for循环内部所有对象都在一次for循环中生存,当结束一次for循环后lock对象会自动析构
        for(int i = 0;;i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            std::unique_lock<std::mutex> lock(mtx);  //在类实例化后会立即上锁
            std::cout << "producing " << i << std::endl;
            produced_nums.push(i);
            notified = true;
            // lock.unlock();     //可以不用加锁
            cv.notify_all();  // 也可以notifiy.one() (signal)用于唤醒一个线程
        }
    };


    auto consumer = [&](){
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while(!notified) //避免虚假唤醒(异步问题)
        {
            cv.wait(lock);
        }
        // 短暂取消锁,使得生产者有机会在消费者消费空前继续生产
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        lock.lock();
        while(!produced_nums.empty())
        {
            std::cout << "consuming " << produced_nums.front() << std::endl;
            produced_nums.pop();
        }
        notified = false;
    }};

    // 分别在不同的线程中运行
    std::thread p(producer);
    std::thread cs[2];
    for(int i = 0;i < 2;i++)
    {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for(int i = 0;i < 2;i++)
    {
        cs[i].join();
    }
    return 0;
}