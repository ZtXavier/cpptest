#ifndef A886574A_F207_4879_8AB7_4875415205DB
#define A886574A_F207_4879_8AB7_4875415205DB
#include<iostream>
#include<cctype>
#include<string>

template<class T>
class Arrary
{
public:
    //有参构造 参数 容量
    Arrary(int capa)
    {
        std::cout <<"构造器调用 " << std::endl;
        this->a_capacity = capa;
        this->a_size = 0;
        this->Pa = new T[this->a_capacity];          //新开一个容量为capa的数组
    }

    //析构函数
    ~Arrary()
    {
        std::cout <<"析构器调用" << std::endl;
        if(this->Pa != NULL)
        {
            delete[] this->Pa;
            this->Pa = NULL;
        }
    }

    //拷贝构造函数
    Arrary(const Arrary &arr)
    {
        std::cout << "拷贝构造和函数" << std::endl;
        this->a_capacity = arr.a_capacity;
        this->a_size = arr.a_size;
        this->Pa = new T[arr.a_capacity];
        for(int i = 0;i < this->a_size;i++)
        {
            this->Pa[i] = arr.Pa[i];
        }
    }

    //operation= 防止浅拷贝的问题
    Arrary &operator=(const Arrary &arr)
    {
        std::cout << "赋值构造函数" << std::endl;
        if(this->Pa != NULL)
        {
            this->a_capacity = 0;
            this->a_size = 0;
            delete [] this->Pa;
            this->Pa = NULL;
        }
        //深拷贝
        this->a_capacity = arr.a_capacity;
        this->a_size = arr.a_size;
        this->Pa = new T [this->a_capacity];
        for(int i = 0;i < this->a_size;i++)
        {
            this->Pa[i] = arr.Pa[i];
        }
        return *this;
    }

    T &operator[](int n)                   //如果要实现通过数组下标来访问数组内的元素 例如 arr[0] = 100; 必须要有&引用才能真正对这个数组赋值，否则将返回对这个数组的拷贝
    {
        return this->Pa[n];
    }

    void Push_back(const T &num)
    {
        if(this->a_size == this->a_capacity)
        return;
        this->Pa[this->a_size] = num;
        this->a_size++;
    }

    void Pop_arr()
    {
        if(this->a_size == 0)
        return;
        this->a_size--;
    }

    int _Size()
    {
        return this->a_size;
    }

    int _Capacity()
    {
        return this->a_capacity;
    }



private:
    T * Pa;
    int a_capacity;
    int a_size;
};







#endif /* A886574A_F207_4879_8AB7_4875415205DB */
