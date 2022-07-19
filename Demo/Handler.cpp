#include"Head.hpp"


Handler::Handler(int fd):fd_(fd),events_(0),revents_(0),isInEpoll_(false),len_(0)
{

}


Handler::~Handler()
{

}

void Handler::handlerEvent()
{
    if(revents_ & EPOLLIN)
    {
        readcallback_(fd_);
    }
    if(revents_ & EPOLLOUT)
    {
        writecallback_(fd_);
    }
}

void Handler::setReadCallback(EventCallback_ cb)
{
    readcallback_ = cb;
}
void Handler::setWriteCallback(EventCallback_ cb)
{
    writecallback_ = cb;
}
void Handler::setCloseCallback(EventCallback_ cb)
{
    closecallback_ = cb;
}
void Handler::setErrorCallback(EventCallback_ cb)
{
    errorcallback_ = cb;
}

void Handler::enableRead()
{
    events_ = EPOLLIN;
}

void Handler::enableWrite()
{
    events_ = EPOLLOUT;
}

void Handler::enableAll()
{
    events_ |= EPOLLIN | EPOLLOUT;
}

void Handler::disenableAll()
{
    events_ =  0;
}

int Handler::retfd()
{
    return fd_;
}

int Handler::retevents()
{
    return events_;
}

int Handler::rusevents()
{
    return revents_;
}

int Handler::length()
{
    return len_;
}

char *Handler::buff()
{
    return buff_;
}

bool Handler::retboolEpoll()
{
    return isInEpoll_;
}

void Handler::setboolF()
{
    isInEpoll_ = false;
}

void Handler::setboolT()
{
    isInEpoll_ = true;
}

void Handler::setreventsIN()
{
    revents_ = EPOLLIN;
}

void Handler::setreventsOUT()
{
    revents_ = EPOLLOUT;
}

void Handler::setLen(int len)
{
    len_ =  len;
}