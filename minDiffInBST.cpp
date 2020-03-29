#include <iostream>
#include <string>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int min_dif = 100;
int temp1 = -100;
int temp2 = -100;

int minDiffInBST(TreeNode* root) {
    return inorder(root);
}

int inorder(TreeNode* r)
{
    if(!r)
        return min_dif;
    if(r -> left)
        inorder(r -> left);
    temp1 = temp2;
    temp2 = r -> val;
    min_dif = min(min_dif, temp2 - temp1);
    if(r -> right)
        inorder(r -> right);
    return min_dif;
}

int main()
{
    int nums[] = {4,2,6,1,3,NULL,NULL};
    TreeNode* nodes = nums;
    int res = minDiffInBST(nodes);
}