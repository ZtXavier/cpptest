#include<iostream>
#include<cctype>

class stat
{
    public:
        void calulate() {amount += amount * interestRate;}
        static double rate() {return interestRate;}
        static void rate(double);
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
};


int main(void)
{
    double r;
    r = stat::rate();
    
}