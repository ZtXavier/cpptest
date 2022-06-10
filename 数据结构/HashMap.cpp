#include"hash_map.hpp"
#include<iostream>
#include<string>
using namespace std;


class HashFunc
{
    public:
        int operator()(const std::string & k)
        {
            int hash = 0;
            for(int i = 0;i < k.length();++i)
            {
                hash = hash << 7 ^ k[i];
            }
            return (hash & 0x7FFFFFFF);   
        }
};


class EqualKey
{
    public:
        bool operator()(const std::string & A,const std::string & B)
        {
            if(A.compare(B) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};


int main()
{
    _Hash_Map<string, string, HashFunc, EqualKey> hashmap(100);
 
    hashmap.insert("hello", "world");
    hashmap.insert("why", "dream");
    hashmap.insert("c++", "good");
    hashmap.insert("welcome", "haha");
 
    
    cout << "after insert:" << endl;
    cout << hashmap.find("welcome").c_str() << endl;
    cout << hashmap.find("c++").c_str() << endl;
    cout << hashmap["why"].c_str() << endl;
    cout << hashmap["hello"].c_str() << endl;
 
    if (hashmap.del_("hello"))
        cout << "remove is ok" << endl;    //remove is ok
    cout << hashmap.find("hello").c_str() << endl; //not exist print NULL
 
    hashmap["why"] = "love";
    cout << hashmap["why"] << endl;
    return 0;
}