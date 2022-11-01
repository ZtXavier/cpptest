#include<iostream>
#include<memory>

class B;
class A {
    public:
        std::weak_ptr<B> wa;
        void dosomething() {
            std::shared_ptr<B> pa  = wa.lock();
            std::cout << "do something..." << std::endl;
        }

        ~A() {
            std::cout << "delete A" << std::endl;
        }
};

class B {
    public:
        std::shared_ptr<A> pb;


        ~B() {
            std::cout << "delete B" << std::endl;
        }
};


int main() {
    std::shared_ptr<A> sa(new A());
    std::shared_ptr<B> sb(new B());
    if(sa && sb) {
        sa->wa = sb;
        sb->pb = sa;
    }
    sa->dosomething();
    std::cout << "sa use count" << sa.use_count() << std::endl;
    return 0;
}