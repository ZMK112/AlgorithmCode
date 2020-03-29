#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildTree(TreeNode* &root, vector<int>& nums, int lens, int i)
{
    if (i >= lens)
    {
        return;
    }
    root = new TreeNode(nums[i]);
    buildTree(root->left, nums, lens, i * 2 + 1);
    buildTree(root->right, nums, lens, i * 2 + 2);
}

void inorderTravel(TreeNode* root, vector<int>& res)
{
    if (root == NULL)   
    {
        return;
    }

    if (root->left != NULL)
    {
        inorderTravel(root->left, res);
    }

    res.push_back(root->val);

    if (root->right != NULL)
    {
        inorderTravel(root->right, res);
    }
}

TreeNode* Trees(TreeNode* root, vector<int>& nums)
{
    int lens = nums.size();
    buildTree(root, nums, lens, 0);
    return root;
}

int main()
{   
    vector<int> res;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode* root = new TreeNode(-1);
    root = Trees(root, nums);
    inorderTravel(root, res);
    return 0;
}

