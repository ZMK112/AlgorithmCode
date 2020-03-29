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

TreeNode* constructTree(TreeNode*& root, vector<int>& nums,int lens, int i)
{
    if (i > lens){
        return root;
    }

    root = new TreeNode(nums[i]);
    constructTree(root->left, nums, lens, 2 * i + 1);
    constructTree(root->right, nums, lens, 2 * i + 2);
}

TreeNode* Trees(TreeNode*& root, vector<int>& nums)
{
    int lens = nums.size() - 1;
    return constructTree(root, nums, lens, 0);
}

int main()
{   
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> nums(a,a+8);
    TreeNode* root;
    Trees(root, nums);
    return 0;
}