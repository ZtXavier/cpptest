#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

// lambda 表达式的格式 [//获取的序列] (//形参) {//return}

// void elimDup(std::vector<std::string> &sw)
// {
//     std::sort(sw.begin(),sw.end());
//     auto end_unique = std::unique(sw.begin(),sw.end());
//     sw.erase(end_unique,sw.end());
// }

void elimDup(std::vector<std::string> &wd)
{
    std::sort(wd.begin(),wd.end());
    auto end_unique = std::unique(wd.begin(),wd.end());
    wd.erase(end_unique,wd.end());
}

std::string make_plural(size_t ch,const std::string &s,const std::string &s1)
{
    return (ch > 1) ? s + s1 : s;
}

void biggies(std::vector<std::string> &word,std::vector<std::string>::size_type sz)
{
    elimDup(word);//将word按照字典排序
    //按照长度排序，长度相同的单词维持字典排序
    stable_sort(word.begin(),word.end(),[](const std::string &a,const std::string &b){return a.size() < b.size();});
    auto wc =std::find_if(word.begin(),word.end(),[sz](const std::string &a){return a.size() >= sz;});
    auto count = word.end() - wc;
    std::cout << count << " " << make_plural(count,"word","s") << " of lenghth" << sz << " or longer" << std::endl;
    std::for_each(wc,word.end(),[](const std::string &s){std::cout << s << " ";});
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> s1 = {"dawdad","hrgde","pqrhw","a","wqssf","a","w","a"};
    biggies(s1,s1.size());
    return 0;
}
