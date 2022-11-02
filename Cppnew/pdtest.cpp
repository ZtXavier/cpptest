#include<iostream>
#include<deque>
#include<queue>
#include"priority_queue.hpp"

int main() {
    Maxqueue<int> mq(10);
    std::priority_queue<int> pq;
    mq.Insert(3);
    mq.Insert(1);
    mq.Insert(10);
    mq.Insert(2);
    mq.Insert(5);
    std::cout << mq.Size() << std::endl;
    std::cout << mq.Top() << std::endl;
    

    return 0;
}