//实现图的创建和两种遍历
#include<iostream>
#include<vector>
#include<cassert>
#include<stack>
#include<queue>
#include<algorithm>
#include<stdio.h>

//用邻接表实现存储

// class my_graph{
// public:
//     my_graph(int v)
//     {
//         this->v = v;
//         this->e = 0;
//         for(int i = 0;i < v;i++)
//         {
//             g.push_back(std::vector<int> ());
//         }
//     }
//     // ~my_graph();

//     void my_sort(std::vector<std::vector<int>> &g,int tp)
//     {
//         for(int i = 0;i < g[tp].size() - 1;i++)
//         {
//             for(int j = 0;j < g[tp].size() - 1 - i;j++)
//             {
//                 int tmp;
//                 if(g[tp][j] < g[tp][j+1])
//                 {
//                     tmp = g[tp][j];
//                     g[tp][j] = g[tp][j+1];
//                     g[tp][j+1] = tmp;
//                 }
//             }
//         }
//     }
    
//     int has_e(int from,int to)
//     {
//         assert(from >= 0 && from < this->v);
//         assert(to >= 0 && to < this->v);
//         for (int i = 0;i < g[from].size();i++)
//         {
//             if(g[from][i] == to)
//             {
//                 return 1;
//             }
//         }
//         return 0;
//     }

//     void add_e(int from,int to)
//     {
//         assert(from >= 0 && from < this->v);
//         assert(to >= 0 && to < this->v);
//         g[from].push_back(to);
//         if(has_e(from,to))
//         {
//             g[to].push_back(from);
//         }
//         this->e++;
//     }

//     void print_g()
//     {
//         for(int i = 0;i < v;i++)
//         {
//             std::cout << i << "的邻接表:";
//             for(int j = 0;j < g[i].size();j++)
//             {
//                 std::cout << g[i][j] << " ";
//             }
//             std::cout << std::endl;
//         }
//     }

//     void dfs(int n)
//     {
//         std::vector<bool> arrived(this->v,false);
//         std::stack<int> st;
//         st.push(n);
//         std::cout << "dfs: ";
//         while(!st.empty())
//         {
//             int tp = st.top();
//             if(!arrived[tp])
//             {
//                 std::cout << tp << " ";
//                 arrived[tp] = true;
//             }
//             st.pop();
//             my_sort(g,tp);
//             for(int i = 0;i < g[tp].size();i++)
//             {
//                 if(!arrived[g[tp][i]])
//                 {
//                     st.push(g[tp][i]);
//                 }
//             }
//         }
//         std::cout << std::endl;
//     }

//     void bfs(int n)
//     {
//         std::queue<int> qe;
//         std::vector<bool> arrived(this->v,false);
//         qe.push(n);
//          std::cout << "bfs: ";
//         while(!qe.empty())
//         {
//             int tp = qe.front();
//             if(!arrived[tp])
//             {
//                 std::cout << tp << " ";
//                 arrived[tp] = true;
//             }
//             qe.pop();
//             for(int i = 0;i < g[tp].size();i++)
//             {
//                 if(!arrived[g[tp][i]])
//                 {
//                     qe.push(g[tp][i]);
//                 }
//             }
//         }
//         std::cout << std::endl;
//     }

// private:
//     int v,e;          //这里两个变量分别代表结点和边
//     std::vector<std::vector<int>> g;
// };

//用邻接矩阵的方式存储

class my_graph{
public:
    my_graph(int v)
    {
        this->v = v;
        this->e = 0;
        for(int i = 0;i < v;i++)
        {
            g.push_back(std::vector<int>(v,0));
        }
    }
    ~my_graph() = default;
    
    int has_e(int from,int to)
    {
        assert(from >= 0 && from < this->v);
        assert(to >= 0 && to < this->v);
            if(g[from][to] == 1)
            {
                return 1;
            }
        return 0;
    }

    int add_e(int from,int to)
    {
        assert(from >= 0 && from < this->v);
        assert(to >= 0 && to < this->v);
        if(has_e(from,to))
        {
           return 1;
        }
        g[from][to] = 1;
        g[to][from] = 1;
        this->e++;
        return 0;
    }

    void print_g()
    {
        std::cout << "矩阵表: " << std::endl;

        for(int i = 0;i < v;i++)
        {
            std::cout << i << "\t";
        }

        std::cout << "\n\n" << std::endl;

        for(int i = 0;i < v; i++)
        {
            
            for(int j = 0;j < v;j++)
            {
                std::cout << g[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void dfs(int n)
    {
        assert(n >= 0 && n < this->v);
        std::vector<bool> arrived(this->v,false);
        std::stack<int> st;
        st.push(n);
        std::cout << "dfs: ";
        while(!st.empty())
        {
            int tp = st.top();
            if(!arrived[tp])
            {
                std::cout << tp << " ";
                arrived[tp] = true;
            }
            st.pop();
            for(int i = v;i >= 0;i--)
            {
                if(!arrived[i] && g[tp][i] == 1)
                {
                    st.push(i);
                }
            }
        }
        std::cout << std::endl;
    }

    void bfs(int n)
    {
        assert(n >= 0 && n < this->v);
        std::queue<int> qe;
        std::vector<bool> arrived(this->v,false);
        qe.push(n);
        std::cout << "bfs: ";
        while(!qe.empty())
        {
            int tp = qe.front();
            if(!arrived[tp])
            {
                std::cout << tp << " ";
                arrived[tp] = true;
            }
            qe.pop();
            for(int i = 0;i < v;i++)
            {
                if(!arrived[i] && g[tp][i] == 1)
                {
                    qe.push(i);
                }
            }
        }
        std::cout << std::endl;
    }

private:
    int v,e;          //这里两个变量分别代表结点和边
    std::vector<std::vector<int>> g;
};


int main()
{
    int v,e;
    std::cin >> v >> e;
    int from,to;
    my_graph g(v);
    for(int i = 0;i < e;i++)
    {
        std::cin >> from >> to;
        g.add_e(from,to);
    }
    g.print_g();
    g.bfs(0);
    g.dfs(0);
    return 0;
}
