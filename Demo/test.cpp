#include<iostream>
#include<functional>
#include<memory>
#include<unistd.h>
#include<sys/types.h>
#include<sys/epoll.h>
#include<netinet/in.h>


typedef std::function<int(int,int)> func;
class B
{
    public:
    bool registeredcb(int a,int b)
    {
        fun1(a,b);
        return true;
    }
    void setcallback(func cb)
    {
        fun1 = cb;
    }
    private:
        func fun1;

};
class A
{
    public:
        A():handler(new B)
        {

        }
        void start()
        {
            handler->setcallback(std::bind(&A::output,this,std::placeholders::_1,std::placeholders::_2));
            handler->registeredcb(3,2);
        }


        int output(int a,int b)
        {
            std::cout << "output "  << a*b << std::endl;
            
            return a*b;
        }
    private:
        std::unique_ptr<B> handler;
};


int main()
{
   A test;
    test.start();
    return 0;
}