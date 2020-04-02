#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* bool symmetric(TreeNode* a, TreeNode* b)
{
    if (a == nullptr && b == nullptr)
    {
        return true;
    }

    if (a == nullptr || b == nullptr)
    {
        return false;
    }
    
    if (a->val != b->val)
    {
        return false;
    }
    
    return symmetric(a->left, b->right) && symmetric(a->right, b->left);
} */

bool symmetric(TreeNode* a, TreeNode* b)
{
    stack<TreeNode*> s;
    s.push()
}

bool isSymmetric(TreeNode* root) 
{
    return symmetric(root, root);
}