#ifndef _HEAD_HPP_
#define _HEAD_HPP_
#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<sys/epoll.h>
#include<unistd.h>
#include<assert.h>
#include<memory>
#include<boost/noncopyable.hpp>

typedef std::function<void(int )> EventCallback_;

// Handler 处理回调函数,其中包括设置事件属性,读取缓冲区
class Handler : boost::noncopyable
{
    // friend class Acceptor;
    public:
        Handler(int);
        ~Handler();
        void handlerEvent();
        void setReadCallback(EventCallback_);
        void setWriteCallback(EventCallback_);
        void setCloseCallback(EventCallback_);
        void setErrorCallback(EventCallback_);
        void enableRead();
        void enableWrite();
        void enableAll();
        void disenableAll();
        int retfd();
        int retevents();
        int rusevents();
        int length();
        bool retboolEpoll();
        void setboolT();
        void setboolF();
        void setreventsIN();
        void setreventsOUT();
        char *buff();
        void setLen(int len);
    private:
        EventCallback_ readcallback_;
        EventCallback_ writecallback_;
        EventCallback_ closecallback_;
        EventCallback_ errorcallback_;
        int fd_;
        int events_;
        int revents_;
        bool isInEpoll_;
        char buff_[4096];
        int len_;
};

// 用于接受内核发出的响应请求,然后放入到请求队列中
class Acceptor :boost::noncopyable
{
        typedef std::vector<epoll_event> EventList;
    public:
        Acceptor();
        ~Acceptor();
        void update(Handler *);
        void remove(Handler *);
        std::vector<Handler*> poll();
        static const int event_size = 16;
        private:
            int epfd_;
            std::vector<Handler*> fillActivechannels(int);
            EventList activeEventlist_;
};

// 主要进行一个调度分配工作
class Reactor
{
    public:
        Reactor():poller_(new Acceptor){}
        void registerHandler(Handler *);
        void removeHandler(Handler *);
        void loop();

    private:
        std::unique_ptr<Acceptor> poller_;
};

#endif