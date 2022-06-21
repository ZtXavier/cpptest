#ifndef _SPEECH_HPP_
#define _SPEECH_HPP_
#include<iostream>
#include<vector>
#include<map>
#include"speaker.hpp"


class Speech
{
    public:
        Speech();
        ~Speech();

        void show_Menu();

        void init_Speech();

        void exit_Menu();

        void SpeechDraw(); // 抽签

        void complete_begin();

        void Speech_create();

        std::vector<int> speaker_s1; 

        std::vector<int> speaker_s2;

        std::vector<int> Victor;

        std::map<int,Speaker> m_speaker;

        int time;
};





#endif 