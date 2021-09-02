#ifndef SCREEN_H
#define SCREEN_H
#include<iostream>
#include<cctype>
#include<string>

class Screen
{
    friend class window_mgr;
    public:
    typedef std::string::size_type pos;
    // using pos = std::string::size_type;

    pos size() const
    {
        return height * width;
    }

    Screen() = default;                     //默认构造函数
    Screen(pos ht,pos wd) : height(ht),width(wd),contents(ht*wd,' ')
    {
    }
    Screen(pos ht,pos wd,char c) : height(ht),width(wd),contents(ht*wd,c)
    {
    }
    // char get() const                       //读取光标处的字符
    // {
    //     return contents[cursor];           //隐式内联
    // }
    // inline char get(pos ht,pos wd) const;  //显式内联
    Screen move(pos r,pos c);             //能在之后被设置为内联
    Screen set(char);
    Screen set(pos,pos,char);
    Screen display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        
        return *this;
    }

    private:
    pos cursor = 0;
    pos height = 0,width = 0;
    std::string contents;
    void do_display(std::ostream &os) const
    {
        os << contents;
    }

};

// char Screen::get(pos r,pos c) const
// {
//     return contents[r * width + c];
// }

inline Screen Screen::move(pos r,pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r,pos c,char ch)
{
    contents[r * width + c] = ch;
    return *this;
}




#endif



