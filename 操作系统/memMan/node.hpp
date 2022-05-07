#ifndef _NODE_HPP_
#define _NODE_HPP_
#include"table.hpp"
#include<iostream>

class Node
{

public:
    Table ElemTable;
    Node * prior_;
    Node * next_;
    Node(int num,long address,long length,int state):ElemTable(num,address,length,state)
    {
        prior_ = nullptr;
        next_ = nullptr;
    }
    Node(int num,long address,long length,int state,Node *pre,Node*next):Node(num,address,length,state)
    {
        prior_ = pre;
        next_ = next;
    }
};







#endif