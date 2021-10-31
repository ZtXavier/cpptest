#ifndef DEBBDBC6_D448_466E_B053_85F3DE84265A
#define DEBBDBC6_D448_466E_B053_85F3DE84265A
#include<iostream>
#include<string>
#include<vector>

class date
{
public:
    date() = default;
    date(std::string &s1);
    friend std::ostream & operator << (std::ostream& out,const date& day);

    unsigned yr() const {return year;}
    unsigned mon() const {return month;}
    unsigned dy() const {return day;}

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

    const std::string month1[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    const std::string  month2[] = {"January","February","March","April","May","June","July","August","september","October","November","December"};
    const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

inline int get_month(std::string &ds,int &end_of_month)
{
    int i,j;
    int flag = 0;
    for(i = 0; i < 12;i++)
    {
        for(j = 0;j <= month1[i].size();j++)
        {
            if(ds[j] != month1[i][j])
            {
                if(j == month1[i].size())
                {
                    flag = 1;
                    break;
                }
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
        if( i == 12 && flag == 1)
        {
            throw std::invalid_argument("月份简写输入错误");
        }
        if(ds[j] == ' ')
        {
            end_of_month = j+1;      //在这里用j+1来保存ds字符串位置，也就是day的开端
            return i+1;              //返回月份
        }

    for(i = 0; i < 12;i++)
    {
        for(j = 0;j <= month2[i].size();j++)
        {
            if(ds[j] != month2[i][j])
            {
                if(j == month2[i].size())
                {
                    flag = 1;
                    break;
                }
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
        if( i == 12 && flag == 1)
        {
            throw std::invalid_argument("月份简写输入错误");
        }

        if(ds[j] == ' ')
        {
            end_of_month = j+1;      //在这里用j+1来保存ds字符串位置，也就是day的开端
            return i+1;              //返回月份
        }
    return 0;
}

inline int get_day(std::string &ds,int mon,int &p)
{
    size_t q;
    int day;
    day = stoi(ds.substr(p),&q,10);
    if(day < 1 || day > days[mon-1])
    throw std::invalid_argument("日期输入错误");
    p += q;
    return day;
}

inline int get_year(std::string &ds,int &p)
{
    int year;
    size_t q;
    year = std::stoi(ds.substr(p),&q,10);
    if(p + q != ds.size())
    throw std::invalid_argument("结尾出错");
    return year;
}


date::date(std::string &s1)
{
    int p;
    size_t q;
    if((p = s1.find_first_of("0123456789")) == s1.npos)
    {
        throw std::invalid_argument("输入错误");
    }
    if(p > 0)
    {
        month = get_month(s1,p);
        day = get_day(s1,month,p);
        if(s1[p] != ' '&& s1[p] != ',')
        throw std::invalid_argument("间隔符error");
        p++;
        year = get_year(s1,p);
    }
    else
    {
        month = stoi(s1,&q);
        p = q;
        if(month < 1 || month > 12)
        {
            throw std::invalid_argument("月错误");
        }
        if(s1[p++] != '/')
        {
            throw std::invalid_argument("间隔符错误");
        }
        day = get_day(s1,month,p);
        if(s1[p++] != '/')
        {
            throw std::invalid_argument("间隔错误");
        }
        year = get_year(s1,p);
    }
}
std::ostream & operator << (std::ostream &out,const date &d)
{
    out << d.yr() << "年" << d.mon()  << "月" << d.dy() << "日" <<std::endl;
    return out;
}


#endif /* DEBBDBC6_D448_466E_B053_85F3DE84265A */
