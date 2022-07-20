#include<iostream>
#include<event2/event.h>
#include<memory>
#include<unistd.h>
#include<mutex>
#include<thread>
#include<list>

class Task
{
public:
    Task() = default;
    virtual ~Task() = default;
    virtual void init() = 0;
    void set_thread_id(int thread_id);
    void set_event_base(std::shared_ptr<event_base> base);
    void setsock(int sock);
    int get_sock() const;
    int get_thread_id() const;
    event_base *get_event_base() const;
private:
    int sock;
    int thread_id;
    std::weak_ptr<event_base> base;
};

void Task::set_thread_id(int thread_id)
{
    this->thread_id = thread_id;
}

void Task::set_event_base(std::shared_ptr<event_base> base)
{
    this->base = base;
}

void setsock(int sock)
{
    sock = sock;
}

int Task::get_sock() const
{
    return sock;
}

int Task::get_thread_id() const 
{
     return  thread_id;
}

event_base * Task::get_event_base() const 
{
    return base.lock().get();
}


class Thread
{
    public:
        Thread() = default;
        ~Thread() = default;

        void start();
        void set_up();
        void thread_main();
        void active();
        void add_task(std::shared_ptr<Task> tast);
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

void Thread::set_up()
{
    int fds[2];
    if(pipe(fds))
    {
        std::cerr << "pipe() error" << std::endl;
        return;
    }
    notify_fd = fds[1];
    std::shared_ptr<event_config> ev_config(event_config_new(),event_config_free);
    event_config_set_flag(ev_config.get(),EVENT_BASE_FLAG_NOLOCK);

    std::shared_ptr<event_base> temp_base(event_base_new_with_config(ev_config.get()),event_base_free);
    base = temp_base;

    auto *ev = event_new(base.get(),fds[0],EV_READ | EV_PERSIST,event_callback,this);
    event_add(ev,nullptr);
}

void Thread::thread_main()
{
    std::cout << "thread" << thread_id << " start" << std::endl;
    event_base_dispatch(base.get());
    std::cout << "thread " << thread_id << " end" << std::endl;
}

void Thread::active()
{
    ssize_t len = write(notify_fd,"c",1);
    if(len <= 0)
    {
        std::cerr << "active error" << std::endl;
        return;
    }
}

void Thread::add_task(std::shared_ptr<Task> task)
{
    task->set_event_base(base);
    mutex_.lock();
    work_queue.push_back(task);
    mutex_.unlock();
}

void Thread::event_callback(evutil_socket_t sock,short what,void *ctx)
{
    auto *thread = (Thread*)ctx;
    char buffer[2] = {0};
    ssize_t len = read(sock,buffer,sizeof(buffer) - 1);
    if(len <= 0)
    {
        return;
    }
    thread->mutex_.lock();
    if(thread->work_queue.empty())
    {
        thread->mutex_.unlock();
        return;
    }
    std::shared_ptr<Task> tk = thread->work_queue.front();
    thread->work_queue.pop_front();
    thread->mutex_.unlock();
    tk->init();
}

