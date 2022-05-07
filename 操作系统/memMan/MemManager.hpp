#ifndef _MEMMANAGER_HPP_
#define _MEMMANAGER_HPP_
#include"node.hpp"
#include<iostream>

class MemManager
{
    private:
    Node *head;
    int nodenums_;
    int maxLen_;

    public:
    MemManager(int num,long address,long length,int state);
    MemManager(long length);
    // 申请内存
    int requestMemory(long memlong);
    // 分配内存
    int allocateMemory(Node* reAllocMem,long memorylen);
    //释放内存
    void freeMemory(int memoryNum);

    void show();



    int firstFit(long memorylen);
    int bestFit(long memorylen);
    int maxFit(long memorylen);

};








#endif