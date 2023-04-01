
// private:
//     // 这个mp来存放根节点的下表,能够方便找到
//     unordered_map<int,int> mp;

// public:
//     TreeNode *buildTree(vector<int> &preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         // 我们知道先序第一个节点为跟节点,那么构造中序mp
//         for(int i = 0;i < n; ++i) {
//             mp[inorder[i]] = i;
//         } 

//         // 进入我们自己构造的函数,后面的参数构造区间来传入遍历

//         return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
//     }

//     TreeNode*myBuildTree(const vector<int>& pre, const vector<int>& in, int pre_left, int pre_right, int in_left, int in_right) {
//             // 这里需要判断连个序列的个数是否相同
//             int n_pre = pre.size();
//             int n_in = in.size();

//             if(n_pre != n_in) {
//                 return nullptr;
//             }
//             // 前序遍历的第一个是根节点
//             int pre_root_index = pre_left;
//             int in_root_index = mp[pre[pre_root]];
//             // 先建立根节点
//             TreeNode *root = new TreeNode(pre[pre_root_index]);
//             // 拿到左边的子树的个数
//             int size_left_subtree = in_root_index - in_left;

//             root->left = myBuildTree(pre, in, pre_left + 1, pre_left + size_left_subtree, in_left, in_root_index - 1);

//             root->right = myBuildTree(pre, in, pre_left + 1 + size_left_subtree,pre_right, in_left + in_root_index + 1, in_right);

//             return root;
//     }