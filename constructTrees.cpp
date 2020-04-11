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

vector<int> res;

TreeNode* constructTrees(TreeNode*& root, vector<int>& nums,int lens, int i)
{
    if (i > lens){
        return root;
    }

    root = new TreeNode(nums[i]);
    constructTrees(root->left, nums, lens, 2 * i + 1);
    constructTrees(root->right, nums, lens, 2 * i + 2);
    i--;
}

void inorderTravel(TreeNode* root)
{
    if (root == NULL)   
    {
        return;
    }

    if (root->left != NULL)
    {
        inorderTravel(root->left);
    }

    res.push_back(root->val);

    if (root->right != NULL)
    {
        inorderTravel(root->right);
    }
}

TreeNode* Trees(TreeNode*& root, vector<int>& nums)
{
    int lens = nums.size() - 1;
    TreeNode* roots = constructTrees(root, nums, lens, 0);
    return roots;
}

int main()
{   
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // vector<int> nums(a,a+7);
    TreeNode* root;
    Trees(root, nums);
    return 0;
}