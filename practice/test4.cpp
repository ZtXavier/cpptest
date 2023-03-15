#include<iostream>

 // 虚基类的创建需要派生子类来实现
// template <typename T> class A {
//     friend T;
//     private:
//         A(){}
//         ~A(){}
// };


// class B : virtual public A<B> {
//     public:
//         B() {}
//         ~B() {}
// };

// class C : virtual public B {
//     public:
//         C() {}
//         ~C() {}
// };

// int main() {
//     B b;
//     return 0;
// }
using namespace std;
class A 
{ 
 	virtual void g() 
 	{ 
 	 	cout << "A::g" << endl; 
 	} 
private: 
 	virtual void f() 
 	{ 
 	 	cout << "A::f" << endl; 
 	} 
}; 
class B : public A 
{ 
 	void g() 
 	{ 
 	 	cout << "B::g" << endl; 
 	} 
 	virtual void h() 
 	{ 
 	 	cout << "B::h" << endl; 
 	} 
}; 
typedef void( *Fun )( void ); 
int main() 
{ 
 	B b; 
 	Fun pFun; 
 	for(int i = 0 ; i < 3; i++) 
 	{ 
 	 	pFun = *( Fun* )( ( int *)  ( int* )( &b  + i ) ); 
 	 	pFun(); 
 	} 	 
     return 0;
} 

// 四个人,手电17 2个人过桥  1 ,1 2 ,2 3 ,5 4 ,10