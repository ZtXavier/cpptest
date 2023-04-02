#include<iostream>
// int j = 10;

// int main() {
    // int i = 0;

    // int j = 1;

    // j = j + 1;
    // std::cout << j << std::endl;

//     return 0;
// }



class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        // 如果先序里面没有值,那么直接返回
        if(!preorder.size()) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);

        stack<TreeNode*> st;
        // 先将根压入栈
        st.push(root);

        int inorderindex = 0;

        for(int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode *node = st.top();
            if(node->val != inorder[inorderindex]) {
                node->left = new TreeNode(preorderVal);
                st.push(node->left);
            } else {
                while(!st.empty() && st.top()->val == inorder[inorderindex]) {
                    node = st.top();
                    st.pop();
                    ++inorderindex;
                }
                node->right = new TreeNode(preorderVal);
                st.push(node->right);
            }
        }   
        return root;
    }
};
