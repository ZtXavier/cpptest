#include<iostream>
#include<vector>



int main()
{
    std::vector<std::string> svec;
    svec.reserve(8);
    std::string word;
    std::cout << svec.capacity() << std::endl;
    while(std::cin >> word)
    {
        svec.push_back(word);
    }
        svec.resize(svec.size()+svec.size()/2);      //我们在此处进行一个有效内存的开辟
        std::cout << svec.size() << std::endl;
        std::cout << svec.capacity() << std::endl;
    return 0;
}