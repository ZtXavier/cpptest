#include<iostream>
#include<event2/event.h>
#include<memory>
#include<mutex>
#include<thread>
#include<list>

class Task;
class Thread
{
    public:
        Thread() = default;
        ~Thread() = default;

        void start();
        void set_up();
        void thread_main();
        void active();
        void add_tast(std::shared_ptr<Task> tast);
        static void event_callback(evutil_socket_t sock,short what,void *ctx);

        void set_thread_id(int thread_i)
        {
            this->thread_id = thread_i;
        }

        int get_thread_id() const
        {
            return thread_id;
        }
    private:
        int thread_id;
        std::shared_ptr<event_base> base;
        int notify_fd;
        std::mutex mutex_;
        std::list<std::shared_ptr<Task>> work_queue;
};

void Thread::start()
{

    set_up();

    // 创建主线程
    std::thread th(&Thread::thread_main,this);

    th.detach();
}

void set_up()
{
    int fds[2];
    if(pipe(fds))
    {
        
    }
}