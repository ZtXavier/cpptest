#include"speech.hpp"
#include"speaker.hpp"
#include<algorithm>


Speech::Speech()
{
    this->init_Speech();
    this->Speech_create();
}

Speech::~Speech()
{

}

void Speech::show_Menu()
{
    std::cout << ">欢迎来到演讲比赛系统<" << std::endl;
    std::cout << "       1.Begin" << std::endl;
    std::cout << "       2.check" << std::endl;
    std::cout << "       3.clear" << std::endl;
    std::cout << "       0.return" << std::endl;
}

void Speech::exit_Menu()
{
    std::cout << "welcome use it next time" << std::endl;
    std::cout << "put anything to continue..." << std::endl;
    getchar();
    getchar();
}

void Speech::init_Speech()
{
    this->speaker_s1.clear();
    this->speaker_s2.clear();
    this->Victor.clear();
    this->m_speaker.clear();

    this->time = 1;  //比赛轮数
}

void Speech::SpeechDraw()
{
    std::cout << "第 " << this->time << "轮选手正在抽签" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "抽签后的结果如下:" << std::endl;
    if(this->time == 1)
    {
        std::random_shuffle(speaker_s1.begin(),speaker_s1.end());
        for(std::vector<int>::iterator it = speaker_s1.begin(); it != speaker_s1.end();++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else
    {
         std::random_shuffle(speaker_s2.begin(),speaker_s2.end());
        for(std::vector<int>::iterator it = speaker_s2.begin(); it != speaker_s2.end();++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    getchar();
}

void Speech::complete_begin()
{
    SpeechDraw();

} 

void Speech::Speech_create()
{
    std::string nameseed = "ABCDEFGHIJKL";
    for(int i = 0;i < nameseed.size();i++)
    {
        std::string name = "选手";
        name += nameseed[i];

        Speaker spk;
        spk.s_name = name;
        for(int i = 0;i < 2;i++)
        {
            spk.m_score[i] = 0;
        }

        this->speaker_s1.push_back(i+10001);
        this->m_speaker.insert(std::make_pair(i+10001,spk));
    }
}