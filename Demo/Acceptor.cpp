#include"Head.hpp"
#include<iostream>

Acceptor::Acceptor():activeEventlist_(event_size)
{
    epfd_ = epoll_create1(EPOLL_CLOEXEC);
}

Acceptor::~Acceptor()
{
    close(epfd_);
}

void Acceptor::update(Handler *handler)
{
    epoll_event epvt;
    epvt.events = handler->retevents();
    epvt.data.ptr = handler;
    int op;
    if(handler->retboolEpoll())
    {
        op = EPOLL_CTL_MOD;
    }
    else
    {
        op = EPOLL_CTL_ADD;
    }
    handler->setboolT();
    int ret = epoll_ctl(epfd_,op,handler->retfd(),&epvt);
    if(ret < 0)
    {
        printf("epoll_ctl error on fd :%d\n",handler->retfd());
    }
    else
    {
        printf("epoll_ctl on fd :%d success!\n",handler->retfd());
    }
}

void Acceptor::remove(Handler * handler)
{
    assert(handler->retboolEpoll());
    handler->setboolF();
    int op = EPOLL_CTL_DEL;
    int ret = epoll_ctl(epfd_,op,handler->retfd(),NULL);
    if(ret < 0)
    {
         printf("epoll_ctl error on fd :%d\n",handler->retfd());
    }
    else
    {
        printf("epoll_ctl on fd :%d success!\n",handler->retfd());
    }
}

std::vector<Handler*> Acceptor::fillActivechannels(int activenums)
{
    std::vector<Handler*> actives;
    for(int i = 0;i < activenums;i++)
    {
        Handler *handlerPtr = static_cast<Handler*>(activeEventlist_[i].data.ptr);
        if(activeEventlist_[i].events & EPOLLIN)
        {
            handlerPtr->setreventsIN();
        }
        if(activeEventlist_[i].events & EPOLLOUT)
        {
            handlerPtr->setreventsOUT();
        }
        actives.push_back(handlerPtr);
    }
    return actives;
}

std::vector<Handler*>Acceptor::poll()
{
    std::vector<Handler*> activeEventPtr;
    int nready = epoll_wait(epfd_,activeEventlist_.data(),activeEventlist_.size(),-1);
    if(nready > 0)
    {
        activeEventPtr = fillActivechannels(nready);
        if(nready == activeEventlist_.size())
        {
            activeEventlist_.resize(activeEventlist_.size() * 2);
        }
    }
    else if(nready == 0)
    {

    }else
    {
        printf("nready = %d,error\n",nready);
    }
    return activeEventPtr;
}





