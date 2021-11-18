#include<iostream>
#include<string>
#include<algorithm>
#define MAX 32




int strRplace(std::string &S,std::string &T,std::string &V)
{
    // int pos,i;
    // char in[] = "awdawd";
    // char *res;
    // res = strchr(S,'d');
    // res = index(S,'d');
    // pos = res - S;
    // printf("%d",pos);

    int pos;
    pos = S.find(T);
    // std::cout << (pos = S.find_first_of(T));
    if(pos == -1)
    return 0;
        int len = T.length() - V.length();
        std::cout << len;
        if(len == 0)
        {
            for(int i = 0;i < V.length();i++)
            {
                S[pos+i] = V[i];
            }
        }
        else if(len > 0)
        {
            for(int i = pos + len;i < S.length() - len;i++)
            {
                S[i] = S[i+len];
            }
            for(int i = S.length()-len;i < S.length();i++)
            S[i] = '\0';
            for(int i = pos;i < pos + V.length();i++)
            {
                S[i] = V[i - pos];
            }
        }
        else //此时len < 0;
        {
            len = (-len);
            if(S.length()+len <= MAX)
            {
                std::string b(len,'a');         //这一步为了使其有效长度增加
                S  = S + b;
                for(int i = S.length();i >= pos + T.length();i--)
                {
                    S[i+len] = S[i];
                }
                for(int i = pos;i < pos+V.length();i++)
                {
                    S[i] = V[i-pos];
                }
            }
            else if(S.length() + len > MAX)
            {
                    std::string b(MAX - S.length(),'a');
                    S  = S + b;
                    if(pos + V.length() <= MAX)
                    {
                        for(int i = MAX - 1;i >= pos + V.length();i--)
                        {
                            S[i] = S[i-len];
                        }
                        for(int i = 0;i < V.length();i++)
                        {
                            S[i + pos] = V[i];
                        }
                    }
                    else
                    {
                        for(int i = 0;i < MAX - pos;i++)
                        {
                            S[i+pos] = V[i];
                        }
                    }
            }
        }
        return 1;
    }




int main()
{
    // char S[MAX] = "asdffa";
    // char T[] = "ffa";
    // char V[] = "lkj";

    std::string S(MAX,'\0');
    S = "asdffabdafawfaw";
    // S += "ada";
    // std::cout << S;
    std::string T = "dffa";
    std::string V = "lkjwlllllllllllllllllllllaaabbbcccdddd";
    strRplace(S,T,V);
    std::cout << S;
    return 0;
}