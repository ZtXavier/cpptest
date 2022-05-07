#ifndef _TABLE_HPP_
#define _TABLE_HPP_



class Table
{
    public:
        Table(int num,long address,long length,int state):num_(num),address_(address),length_(length),state_(state)
        {

        }
        int state_;
        int num_;
        long address_;
        long length_;
};


#endif