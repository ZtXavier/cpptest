#include<iostream>
#include<memory>

void test() {
    std::shared_ptr<int> sptr;
    sptr.reset(new int);
    *sptr = 10;

    std::weak_ptr<int> weak1 = sptr;
    sptr.reset(new int);
    *sptr = 5;
    std::weak_ptr<int> weak2 = sptr;
    std::cout << weak1.expired() << std::endl;

    std::cout  << weak2.lock() << std::endl;
    std::cout  << weak1.lock() << std::endl;
    std::cout << sptr.use_count() << std::endl;
    std::cout << sptr << " :" << *sptr << std::endl;
}



int main() {
    test();
    return 0;
}