#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    float a,b;
    while(1){
        try{
            cin >> a >> b;
            if(b == 0)
            throw runtime_error("除数 not be zero !!!"); //在判断条件之前要先抛出一个问题语句
            a = a/b;
            break;
        }
        catch(runtime_error err){              //处理问题语句
            cout << err.what()                 //打印出问题所在(自定义的提示)
            << "\n Try Again enter y or n " << endl;
            char c;
            cin >> c;
            if(!cin || c == 'n')
            break;
        }
    }
    cout << a << endl;
    return 0;
}