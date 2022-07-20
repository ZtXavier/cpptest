// #include<iostream>


// // 友元类不能继承
// // 静态成员函数多了一个调用方法 作用域::成员函数名
// class test
// {
//     public:
        
//         void init();
//         void friend  f();
//         friend class test2;
//         private:
//         static int num;
//         int cc;
// };


// class b2 : public test
// {
//     public:
//          b2() = default;
//         void initb();
// };
// // void b2::initb()
// // {
// //     std::cout << cc << std::endl;
// // }

// //静态成员变量必须现在外部实例化才可被访问
// int test::num = 10;

// class test2
// {
//     public:
//         void print2(b2 &a);
//         void aaaa(test &b);
//     private:
//         int a;
// };

// void f()
// {
//     std::cout << 3 << std::endl;
// }

// void test::init()
// {
//     num = 0;
//     cc = 100;
// }

// void test2::aaaa(test &a)
// {
//     std::cout << a.num << std::endl;
//     std::cout << a.cc << std::endl;
// }

// // void test2::print2(b2 &b)
// // {
// //     b.initb();
// // }

// int main()
// {
//     // const int *p = new int[5]{1,2,0,0,4};
//     // std::cout << p[0] << "awd\n\r" << p[4];
//     test t;
//     t.init();
//     b2 b;
//     test2 t2; //friend
//     t2.aaaa(t);
//     // t2.print2(b);

//     return 0;
// }




// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// int main()
// {
//     string num;
//     // getline(cin,num);
//     cin >> num;
//     string n = "1234567890";
//     if(num[0] == '1' && num.size() == 11 && string::npos == num.find_first_not_of(n))
//     {
//         cout << "Yes" << endl;
//     }
//     else cout << "No" << endl;
//     return 0;
// }

