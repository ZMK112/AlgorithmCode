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

/* void swaps(TreeNode* a, TreeNode* b)
{
    TreeNode* tmp = a;
    b = a;
    b = tmp;
} */

TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr)
    {
        return root;
    }
    if (root->left == nullptr &&  root->right == nullptr)
    {
        return root;
    }

    swap(root->left, root->right);
        
    if (root->left)
    {
        mirrorTree(root->left);
    }
    if (root->right)
    {
        mirrorTree(root->right);
    }
    return root;   
}


TreeNode* mirror(TreeNode* root)
{
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode* node = s.top();
        s.pop();
        if (node == nullptr)
        {
            break;
        }
        swap(node->left, node->right);
        s.push(node->left);
        s.push(node->right);
    }
    return root;
}

TreeNode* buildTree(TreeNode* &root, vector<int>& nums, int lens, int i)
{
    if (i >= lens)
    {
        return root;
    }
    root = new TreeNode(nums[i]);
    buildTree(root->left, nums, lens, i * 2 + 1);
    buildTree(root->right, nums, lens, i * 2 + 2);
    return root;
}

int main()
{
    vector<int> one = {4,2,7,1,3,6,9};
    TreeNode* root;
    buildTree(root, one, one.size(), 0);
    mirror(root);
    return 0;
}

