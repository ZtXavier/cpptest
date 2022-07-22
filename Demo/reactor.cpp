#include"Head.hpp"



void Reactor::registerHandler(Handler* handler)
{
    poller_->update(handler);
}

void Reactor::removeHandler(Handler* handler)
{
    poller_->remove(handler);
}

void Reactor::loop()
{
    while(1)
    {
        auto activeEventPtrList = poller_->poll();
        if(!activeEventPtrList.empty())
        {
            for(int i = 0;i < activeEventPtrList.size();i++)
            {
                // 在这里进行回调处理函数
                activeEventPtrList[i]->handlerEvent();
            }
        }
        else
        {

        }
    }
}