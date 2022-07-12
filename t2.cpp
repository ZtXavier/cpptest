#include <cstdio>
#include<iostream>
#include<string>
#include <memory>
#include <thread>
#include <utility>
class Test {
  int a;
  int b;
  Test() = default;
public:
template <class... Args> static std::shared_ptr<Test> create(Args &&...args) {
    class EnableMakeShared : public Test {
    public:
      EnableMakeShared(Args &&...arg) : Test(std::forward<Args>(arg)...) {}
    };
    return std::make_shared<EnableMakeShared>(std::forward<Args>(args)...);
  }
};
void ThreadMain(std::shared_ptr<Test> x) {
  //
  printf("Nothing");
}


int main() {
  auto t = Test::create();
  auto t1 = std::thread(ThreadMain, t);
  t1.detach();
}

// int main()
// { 
//     std::string s;
//     for(;;)
//     {
//         char ch = getchar();
//         if(ch == EOF)
//         {
//             break;
//         }
//         s.push_back(ch);
//     }
//     return 0;
// }