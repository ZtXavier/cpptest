#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_


#include<vector>
template<class T>
class Maxqueue {
    public:
    // 构造容量大小和已有的数量
    Maxqueue(int cap) {
        elts.resize(cap + 1);
        n = 0;
    }

    void Insert(T &&a) {
        ++n;
        elts[n] = a;
        Swim(n);
    }

    void Insert(const T &a) {
        ++n;
        elts[n] = a;
        Swim(n);
    }
    
    T Pop() {
        T max = elts[1];
        Swap(1,n);
        elts[n] = (T)0;
        n--;
        sink(1);
        return max;
    }

    T Top() {
        // 这里需要浪费掉一个资源,为了方便计算
        if(n != 0) {
            return elts[1];
        } else {
            return (T)0;
        }
    }
    
    int Size() {
        return n;
    }

    void Swap(int a, int b) {
        T tmp;
        tmp = elts[b];
        elts[b] = elts[a];
        elts[a] = tmp; 
    }

    bool Empty() {
        return n == 0;
    }

    private:

    int Parent(int root) {
        return root / 2;
    }
    int Right(int root) {
        return root * 2 + 1;
    }
    int Left(int root) {
        return root * 2;
    }

    bool less(int a, int b) {
        return elts[a] < elts[b];
    }

    void sink(int k) {
        while(Left(k) <= n) {
            int maxer = Left(k);
            if(Right(k) <= n && less(maxer, Right(k))) {
                maxer = Right(k);
            }
            if(less(maxer, k)) {
                break;
            }
            Swap(k, maxer);
            k = maxer;
        }
    }

    void Swim(int k) {
        while(k > 1 && less(Parent(k), k)) {
            Swap(Parent(k), k);
            k = Parent(k);
        }
    }

    private:
        //用于存储最大顶堆的元素
        std::vector<T>  elts;
        //当前包含的元素个数
        int n;
};


#endif