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
        this->Pa = new T[this->a_capacity];
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
    private:
    T * Pa;
    int a_capacity;
    int a_size;
};







#endif /* A886574A_F207_4879_8AB7_4875415205DB */
