#include<iostream>
#include<stack>
#include<deque>
#include<algorithm>
#include<vector>

//类的写法
struct treeinfo
{
    treeinfo *left;
    treeinfo *right;
    int data;
    //类的初始化(看成构造函数)
    treeinfo(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

class bintree
{
public:
    bintree(int *data,size_t n,const int &endsign);
    treeinfo *r_createtree(int *data,size_t n,const int &endsign,size_t &index);
    void leveorder();
    void fstprint();
    void midprint();
    void lstprint();
    void r_fstprint();
    void r_midprint();
    void r_lstprint();

private:
    treeinfo *root = NULL;
};

bintree::bintree(int *data,size_t n,const int &endsign)
{
    size_t index = 0;
    this->root = r_createtree(data,n,endsign,index);
}

//二叉树的先序创建
treeinfo *bintree::r_createtree(int *data,size_t n,const int &endsign,size_t &index)
{
    treeinfo *root = NULL;
    if(data[index] != endsign  && index < n) //第二个判断条件为了防止数组的溢出
    {
        root = new treeinfo(data[index]);
        root->left = r_createtree(data,n,endsign,++index);
        root->right = r_createtree(data,n,endsign,++index);
    }
    return root;
}

//非递归先序遍历 根左右
void bintree::fstprint()
{
    treeinfo *cur = root;
    std::stack<treeinfo*> st;
    while(cur != NULL || !st.empty())
    {
        while(cur != NULL)
        {
            std::cout << cur->data << " ";   //在第一次访问时就打印里面的值
            st.push(cur);
            cur = cur->left;
        }
        treeinfo * top = NULL;
        top = st.top();
        st.pop();
        cur = top->right;
    }
    std::cout << std::endl;
}

//非递归中序遍历
void bintree::midprint()
{
    treeinfo *cur = root;
    std::stack<treeinfo*> st;
    while(cur != NULL || !st.empty())
    {
        while(cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        treeinfo * top = NULL;
        top = st.top();
        std::cout << top->data << " ";
        st.pop();
        cur = top->right;
    }
    std::cout << std::endl;
}

//后续遍历 左右根
void bintree::lstprint()
{
    treeinfo *cur = root;
    treeinfo *pre = NULL;        //这里使用来记录右子树是否被访问过
    std::stack<treeinfo*> st;   //后续遍历的话需要将每个子树的根结点保存，所以需要栈
    while(cur!= NULL || !st.empty())
    {
        while(cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        treeinfo *top = st.top();  //如果不新开一个top,直接用cur来保存栈顶元素的话会导致cur一直循环里面保存的值而不更新，死循环
        if(top->right == NULL || top->right == pre) //判断栈顶的元素是否有右子树或者右子树被访问过
        {
            std::cout << top->data << " ";
            st.pop();
            pre = top;
        }
        else
        {
            cur = top->right;
        }
    }
    std::cout << std::endl;
}

void r_f(treeinfo *root)
{
    if(root != NULL)
    {
        std::cout << root->data << " ";
        r_f(root->left);
        r_f(root->right);
    }
}

void r_m(treeinfo *root)
{
    if(root != NULL)
    {
        r_m(root->left);
        std::cout << root->data << " ";
        r_m(root->right);
    }
}

void r_l(treeinfo *root)
{
    if(root != NULL)
    {
        r_l(root->left);
        r_l(root->right);
        std::cout << root->data << " ";
    }
}

void bintree::r_fstprint()
{
    r_f(root);
    std::cout << std::endl;
}

void bintree::r_midprint()
{
    r_m(root);
    std::cout << std::endl;
}

void bintree::r_lstprint()
{
    r_l(root);
    std::cout << std::endl;
}

void bintree::leveorder()
{
    std::deque<treeinfo*> d;
    treeinfo *cur = root;
    if(root == NULL)
    return;
    d.push_back(cur);
    while(!d.empty())
    {
        cur = d.front();
        d.pop_front();
        std::cout << cur->data << " ";
        if(cur->left != NULL)
        {
            d.push_back(cur->left);
        }
        if(cur->right != NULL)
        {
            d.push_back(cur->right);
        }
    }
}



int main()
{
    // int data[] = {1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
    int data[] = {2,5,7,'#','#',6,'#','#',8,10,'#',14,'#','#','#'};
    bintree bt(data,sizeof(data)/sizeof(int),'#');
    bt.lstprint();
    bt.fstprint();
    bt.midprint();
    bt.r_fstprint();
    bt.leveorder();
    return 0;
}