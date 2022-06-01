#include <iostream> 
#include <string> 
using namespace std;
class Student
{
    public:
        Student();
        Student(string name) { this->name = name;}
        string print_(){return name;}
    private:
        string name;
};

int main()
{
    Student st[] = {Student("adwa"),Student("gsgs"),Student("efg"),Student("grgis"),Student("opfe")};
    for(int i = 0;i < 5;i++)
    {
        cout << st[i].print_() << endl;
    }
    return 0;
}