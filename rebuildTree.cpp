#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

TreeNode* rebuildTree(vector<int>& preorder, vector<int>& inorder, 
                int preBegin, int preEnd, int inBegin, int inEnd){
    if (inBegin > inEnd)
    {
        return nullptr;
    }
    int index = 0;

    for(;preorder[preBegin] != inorder[index]; index++);
    
    TreeNode* root = new TreeNode(inorder[index]);

    int leftLens = index - inBegin;

    root->left = rebuildTree(preorder, inorder, preBegin + 1, preBegin + leftLens, inBegin, index - 1);
    root->right =rebuildTree(preorder, inorder, preBegin + leftLens + 1, preEnd,index + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty())
    {
        return nullptr;
    }
    TreeNode* root = rebuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    return root;
}