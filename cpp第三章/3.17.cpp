#include <iostream>
#include <cctype>
#include <vector>
using namespace std;
using std::string;
using std::vector;
int main(void)
{
    string w, w1;
    vector<string> word;
    while (cin >> w)
    {
        cout << w;           //在流中的输入一空格或回车为断点标志
        cout << endl;        //endl类似于'\n'的效果
        w1 = w1 + (w + " "); //在拷贝的同时将流中输入的空格补上
        word.push_back(w);   //向容器中添加字符或其他元素的固定用法
    }

    for (decltype(word.size()) i = 0; i != word.size(); i++)
        cout << word[i];
    cout << endl;
    //cout << "\n";
    for (auto c : w1)
    {
        if (' ' == c)
            cout << "\n";
        else
            cout << (c = toupper(c)); //toupper不可以用在对容器的处理上
    }
    cout << endl;
    return 0;
}