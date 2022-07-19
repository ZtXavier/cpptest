#include<iostream>
#include<boost>

class Counter : boost::noncopyable
{
    Counter() : value_(0) {}
    int64_t value() const;
    int64_t getAndIncrease();
    private:
    int64_t value_;
    mutable MutexLock mutex_;
};

int64_t Counter::value() const
{
    MutexLockGuard lock(mutex_);  //这里是利用了lock的析构晚于返回对象的析构，所以保证了返回数据后才解锁能够被其他
    return value_;
}

int64_t Counter::getAndIncrease()
{
    MutexLockGuard lock(mutex_);
    ino64_t ret = value_++;
    return ret;
}
