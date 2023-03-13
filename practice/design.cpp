#include<iostream>

// 单例模式
// 作用: 保证一个类中只有一个实例,并提供一个访问它的全局访问点,使得系统中只有唯一一个对象实例

// 懒汉模式: 在类加载的时候不创建实例,因此类加载速度快,但获取对象速度慢

// 饿汉模式: 在类加载时就完成了初始化,所以类加载比较慢,但是获取对象速度快

// 主要运用在管理资源,日志,线程池

// 饿汉模式

class Singleton {
    public:
        ~Singleton() {
            std::cout << "destructor called!" << std::endl;
        }
        static Singleton& get_instance() {      //提供一个静态接口,返回静态引用 
            static Singleton instance;
            return instance;
        }
    private:
        Singleton() {
            std::cout << "constructor called!" << std::endl;
        }
        Singleton(const Singleton&)= delete; 
        Singleton& operator=(const Singleton&) = delete;
};

// int main(int argc,char *argv[]) {
//     Singleton& instance_1 = Singleton::get_instance();
//     Singleton& instance_2 = Singleton::get_instance();
//     return 0;
// }



// 当构造函数作为private时
// 也就是说这种对象创建是创建在heap上的,是需要手动释放的
class OnlyHeapClass {
    public:
        static OnlyHeapClass* GetInstance() {
            return (new OnlyHeapClass);
        }
        void print() {
            std::cout << "print" << std::endl;
        }
    private:
        OnlyHeapClass() {}
        ~OnlyHeapClass() {}
};

int main() {
    OnlyHeapClass *p = OnlyHeapClass::GetInstance();
    p->print();
    // delete p;  
    // 如果将该类的析构函数用private修饰的话那么就不能调
    // 用对象来释放,必须是该类内部有自己的实现.这样类的使
    // 用者就必须使用该类设计来(完成自己设计的动作之后)释放类指针
    return 0;
}