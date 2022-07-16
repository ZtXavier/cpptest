#include<iostream>
#include<thread>
#include<mutex>


int v = 1;

void critical_section(int change_v)
{
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);

    v = change_v;

    // 离开此作用域后mtx会被释放
}

// 在并发编程中，推荐使用 std::unique_lock
// 如果你用到了条件变量 std::condition_variable::wait 则必须使用 std::unique_lock 作为参数
// lock_guard不可以显式的调用lock与unlock
int main()
{
    std::thread t1(critical_section,2),t2(critical_section,3);
    t1.join();
    t2.join();

    std::cout << v << std::endl;
    // std::thread t([](){std::cout << 
    // "hello word" << std::endl;});
    // t.join();
    return 0;
}