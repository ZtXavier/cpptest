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
            std::vector<Handler*> fillActivechannels(int);
            int epfd_;
            EventList activeEventlist_;
};

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