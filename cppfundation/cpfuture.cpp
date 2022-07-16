#include<iostream>
#include<future>
#include<thread>


int main()
{
    // packaged_task 用来封装任何调用的目标,来实现异步调用
    std::packaged_task<int()> task([](){return 7;});
    // 在封装好要调用的目标后，可以使用 get_future() 来获得一个 std::future 对象，以便之后实施线程同步
    std::future<int> result = task.get_future();
    std::thread(std::move(task)).detach();
    std::cout << "waiting...";
    result.wait();
    std::cout << "done! " << std::endl << "future result is " << result.get() << std::endl;
    return 0;
}
