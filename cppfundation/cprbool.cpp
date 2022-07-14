//1 An rvalue of arithmetic, enumeration, pointer, or pointer to member type can be converted to an rvalue of type bool.

#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
using foo = void(*)(int);

void func(foo f) 
{
    printf("%p\n",*f);
    std::cout << f << std::endl;
}

int main() 
{
  auto f = [](int value) { std::cout << value << std::endl; };
  func(f);
  func((foo)-5);
  func((foo)5);
  func((foo)0);
  func(nullptr);

  return 0;
}
// 通过测试发现当我们输入的指针不等于0时，返回的cout << f函数都为1,反之为零，说明结果被转为bool值