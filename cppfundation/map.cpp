#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    map<int,int>m;
    int i;
    for(i=0;i<10;i++)
        m[i]=2-i;
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        printf("%d ",it->second);
    return 0;
}
