#include <iostream>
 using namespace std;
  class Rectangle
  { 
      float length; 
      float width;
       float area; 
       bool b; 
       public: Rectangle(float len,float wid);
        float getarea();
         void print();
 }; 
 Rectangle::Rectangle(float len,float wid)
 { 
     length = len;
      width = wid; 
      b = true; 
      if(len <= 0 || wid <= 0)
       b = false; 
} 
float Rectangle::getarea()
{
     return length * width;
} 
void Rectangle::print()
{ 
    float f = getarea();
    if(b) cout<<f<<endl;
} 
int main()
{
     float a,b; 
    cin>>a>>b; 
    Rectangle r(a,b);
    r.print();
    return 0; 
}
