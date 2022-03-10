  #include<iostream>
  #include<algorithm>
  #include<string>
  #include<vector>
class person
{
    public:
        person (std::string name,int age)
        {
            this->name = name;
            this->age = age;
        } 
        bool operator == (const person &p)
        {
            return this->age == p.age && this->name == p.name;
        }   
        std::string name;
        int age;
};




  void test01()
  {
      person p1("aaa",12);
      person p2("bbb",13);
      person p3("ccc",14);


      std::vector<person> list;

      list.push_back(p1);
      list.push_back(p2);
      list.push_back(p3);
    
     std::vector<person>::iterator it = find(list.begin(),list.end(),p2);
     if(it == list.end())
     {
         std::cout << "not find" << std::endl;
     }
     else
     {
         std::cout << (*it).name << (*it).age << std::endl;
     }
  }
  int main()
  {
      test01();
      return 0;
  }