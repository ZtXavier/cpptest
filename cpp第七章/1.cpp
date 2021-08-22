#include <iostream>  
class Animal  
{  
  char* ap;  
public:  
   
  Animal()  
  {  
    ap = new char;  
    std::cout << "Animal ctor" << std::endl;  
  }  
 virtual void foo()  
  {  
    std::cout << "Animal::foo" << std::endl;  
  }  
  virtual ~Animal()  
  {  
    std::cout << "Animal dtor" << std::endl;  
    delete ap;  
  }  
};  
class Dog : public Animal  
{  
  char* dp;  
public:  
  Dog()  
  {  
    dp = new char;  
    std::cout << "Dog ctor" << std::endl;  
  }  
 void foo() 
  {  
    std::cout << "Dog::foo" << std::endl;  
  }  
  ~Dog()  
  {  
    delete dp;  
    std::cout << "Dog dtor" << std::endl;  
  }  
};  
int main()  
{  
  Animal* pa = new Dog();  
  pa->foo();  
  delete pa;  
  return 0;  

}  