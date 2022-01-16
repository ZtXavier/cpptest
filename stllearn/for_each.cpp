#include<iostream>
#include<algorithm>
#include<vector>


void my_print(int val)
{
    std::cout << val << " ";
}

class My_print
{
    public:
        // My_print() {num = 5;}
        void operator()(int val)
        {
            // if(num < val)
            std::cout << val << " ";
        }
        private:
        int num;
};

void test01()
{
    std::vector<int> v1;
    
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }
    // std::for_each(v1.begin(),v1.end(),my_print); 
    std::for_each(v1.begin(),v1.end(),My_print());
    std::cout << std::endl;
}



int main()
{
    test01();
    return 0;
}