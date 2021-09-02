#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include"screen.h"

class window_mgr
{
    public:
    using screenindex = std::vector<Screen>::size_type;
    void clear(screenindex);
    private:
    std::vector<Screen> screens{Screen(24,80,' ')};
};
void window_mgr::clear(screenindex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width,' ');
}