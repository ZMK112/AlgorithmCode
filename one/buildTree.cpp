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

void buildTree(TreeNode* root, vector<int>& nums, int lens, int i)
{
    if (i >= lens)
    {
        return;
    }
    root = new TreeNode(nums[i]);
    buildTree(root->left, nums, lens, i << 1 + 1);
    buildTree(root->right, nums, lens, i << 1 + 2);
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

void Trees(TreeNode** root, vector<int>& nums)
{
    int lens = nums.size();
    buildTree(*root, nums, lens, 0);
}

int main()
{   
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode* root;
    Trees(&root, nums);
    return 0;
}