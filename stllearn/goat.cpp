#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>

class person
{
public:
    person(std::string name,int score)
    {
        this->Name = name;
        this->arg_score = score;
    }
    std::string Name;
    int arg_score;
};

// void printperson(std::vector<person> &p)
// {
//     for(std::vector<person>::iterator it = p.begin();it != p.end();it++)
//     {
//         std::cout << (*it).Name << " 得分: " << (*it).arg_score << std::endl;
//     }
// }

void createperson(std::vector<person> &a)
{
    std::string nameSeed = "ABCDE";
    for(int i = 0;i < 5;i++)
    {
        std::string name = "选手: ";
        name = name + nameSeed[i];
        int score = 0;
        person p(name,score);
        a.push_back(p);
    }
}

void getscore(std::vector<person> &a)
{
    srand((unsigned int) time(0));
    for(std::vector<person>::iterator it = a.begin();it != a.end();it++)
    {
        std::deque<int> d;
        for(int i = 0;i < 10;i++)
        {
            int score = random() % 61 + 40;
            d.push_back(score);
        }

        std::cout << (*it).Name << "得分：";
        for(std::deque<int>::iterator dit = d.begin();dit != d.end();dit++)
        {
            std::cout << (*dit) << " ";
        }
        std::cout << std::endl;

        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        int sum = 0;
        for(std::deque<int>::iterator dit = d.begin();dit != d.end();dit++)
        {
            sum += (*dit);
        }
        sum = sum/d.size();
        std::cout << "去掉最高分和最低分后平均值为:" << sum << std::endl;
        (*it).arg_score = sum;
    }
}


int main()
{
    std::vector<person> p1;
    createperson(p1);
    getscore(p1);
    return 0;
}


