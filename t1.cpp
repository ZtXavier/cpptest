#include<iostream> 
#include<math.h> 
using namespace std;
class Square 
{ 
protected: 
int edge; 
public: 
virtual double GetArea(); 
Square(int edg); 
~Square( ) 
{ } 
}; 
Square::Square(int edg) 
{ edge=edg; } 
//求正方形的面积 
double Square::GetArea() 
{ 
double result; 
result=edge*edge; 
return result; 
} 
//下面的全局函数是专门为了调用虚函数实现运行时的多态性而设计的。 
double objGetArea(Square* base); 
class Rectangle:public Square 
{ 
protected: 
int length; 
//它的宽由正方形类 Square 的成员提供 
public: 
double GetArea(); 
Rectangle(int edg,int leng); 
~Rectangle(){ } 
}; 
double Rectangle::GetArea()//求矩形的面积 
{ 
double result; 
result=length*edge; 
return result; 
} 
Rectangle::Rectangle(int edg,int leng):Square(edg) 
{ 
//调用基类的构造函数 Square(edg)使 edge=edg; 
length=leng; 
} 
double objGetArea(Square* obj) 
{ 
return obj->GetArea(); 
} 

int main() 
{ 
Square Squa1(100); //调用 Square::Square(int)初始化 
Rectangle Rect(200,300);//调用 Rectangle::Rectangle(int,int)初始 
// Squa1 = Rect;

cout<<"正方形 Squa1(100)的面积为："<<Squa1.GetArea()<<endl; 
//静态联编，输出为：10000 
cout<<"正方形 Squa1(100)的面积为："<<objGetArea(&Squa1)<<endl; 
//比较下面两个语句 
cout<<"矩形 Rect(200,300) 的面积为："<<Rect.GetArea()<<endl; 
//静态联编，输出为 60000 
cout<<"矩形 Rect(200,300) 的面积为："<<objGetArea(&Rect)<<endl; 
//动态联编，输出为 60000 
Square *s = &Rect;
cout << s->GetArea() << endl;
return 0; 
} 




