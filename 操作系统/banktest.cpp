#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class banktest
{
    public:
        banktest(const int p,const int w) {_pcNum = p; _wkNum = w;}
        void Max();
        void Allocation();
        void Available();
        void need();
        void safe();

    private:
        std::vector<std::vector<int>> _Maxsrc;
        std::vector<std::vector<int>> _allocation;
        std::vector<std::vector<int>> _need;
        std::vector<int> _avail;
        int _pcNum;
        int _wkNum;
};

void banktest::Max()
{
    cout << "请输入矩阵内容" << endl;
    for(int i = 0;i < _pcNum; ++i)
    {
        vector<int> tmp;
        int resource;
        for(int j = 0;j < _wkNum;++j)
        {
            cin >> resource;
            tmp.push_back(resource);
        }
        _Maxsrc.push_back(tmp);
    }
}

void banktest::Allocation()
{
    cout << "输入各个进程以分配的资源数" << endl;
    for(int i = 0;i < _pcNum;++i)
    {
        vector<int> tmp;
        int resource;
        for(int j = 0;j < _wkNum;++j)
        {
            cin >> resource;
            tmp.push_back(resource);
        }
        _allocation.push_back(tmp);
    }
}


void banktest::Available()
{
    cout << "请输入每个资源现有的数目" << endl;
    int resource;
    for(int i = 0;i < _wkNum;++i)
    {
        cin >> resource;
        _avail.push_back(resource);
    }
}

void banktest::need()
{
    _need.reserve(_pcNum * _wkNum);
    vector<int> tmp(_wkNum,0);
    vector<vector<int>> T(_pcNum ,tmp);
    _need = T;
    for(int i = 0;i < _pcNum;++i)
    {
        for(int j = 0;j < _wkNum;++j)
        {
            _need[i][j] = _Maxsrc[i][j] - _allocation[i][j];
        }
    }
}

void banktest::safe()
{
    while(1)
    {
        while(1)
        {
            vector<int> work = _avail;
            vector<bool> Finish(_pcNum,false);
            int flag1 = 0;
            int routine = 0;
            int *route = new int[_pcNum ];

            for(int i = 0;i < _pcNum;++i)
            {
                for(int p = 0;p < _pcNum;++p)
                {
                    if(Finish[p] == true) continue;
                    flag1 = 0;
                    for(int k = 0;k < _wkNum;++k)
                    {
                        // 如果需要的大于空闲的则分配失败
                        if(work[k] < _need[p][k]) continue;
                        flag1 += 1;
                    }
                    if(flag1 == _wkNum)
                    {
                        Finish[p] = true;
                        for(int f = 0;f < _wkNum;++f)
                        {
                            work[f] += _allocation[p][f];
                            _allocation[p][f] = 0;
                            _need[p][f] = 0;
                        }
                    }
                    route[routine] = p;
                    routine += 1; 
                }
            }
            int flag2 = 0;
            for(int i = 0;i < _pcNum;++i)
            {
                if(Finish[i] == false)
                {
                    cout << "not safe" << endl;
                    break;
                }
                flag2 += 1;
            }
            if(flag2 == _pcNum)
            {
                cout << "is safe" << endl;
                cout << "the routine is :" <<endl;
                for(int i = 0;i < _pcNum;++i)
                {
                    if(i == _pcNum - 1)
                    {
                        cout << route[i] << endl;
                        break;
                    }
                    cout << route[i] << "---->";
                }
            }
            int num;
            cout << "请输入要申请的资源进程号（小于零结束）" << endl;
            cin >> num;
            if(num < 0 || num >= _pcNum)
            {
                break;
            }
            cout << "依次输入各个资源的数量(" << _wkNum << ")" << endl;
            for(int i = 0;i < _wkNum;++i)
            {
                cin >> _need[num][i];
            }
        }
        string jd = "yes";
        cout << "是否再次分配yes/no" << endl;
        cin >> jd;
        if(jd == "no" || jd == "NO")
        {
            break;
        }
    }
}


int main()
{
    int p;
    int w;
    cout << "请输入进程数" << endl;
    cin >> p;
    cout << "请输入资源种类数" << endl;
    cin >> w;
    banktest b(p,w);
    b.Max();
    b.Allocation();
    b.Available();
    b.need();
    b.safe();
    return 0;
}