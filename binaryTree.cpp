#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

// unordered_map<int, int> maps;

// TreeNode* buildTree2(int preL, int inL, int preR)
// {

// }

// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
// {
//     for (int i = 0; i < inorder.size(); i++)
//     {
//         maps[inorder[i]] = i;
//     }
    
//     return buildTree2(0, 0, inorder.size() - 1, preorder);
// }
class Solution{
    public:
        unordered_map<int, int>maps;
        vector<int> preorder;

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
        {   
            for (int i = 0; i < inorder.size(); i++)
            {
                maps[inorder[i]] = i;
            }
            TreeNode* root = buildTree2(0,inorder.size() - 1,0, preorder.size() - 1,preorder);
            return root;
        }

        TreeNode* buildTree2(int preL, int preR, int inL, int inR, vector<int> preorder)
        {
            if (preL > preR || inL > inR){
                return NULL;
            }

            int middle = preorder[preL];
            TreeNode* root = new TreeNode(middle);
            int index = maps[middle];
            root->left = buildTree2(preL + 1, preL + (index - inL), inL, index - 1);
            root->right = buildTree2(preL + (index - inL) + 1, preR, index + 1, inR);
            return root;
        }

    vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> a;
    queue<TreeNode *> tree;
    if(root==NULL)return a;
    TreeNode* r;
    tree.push(root);
    while(tree.size()){
        r=tree.front();
        a.push_back(r->val);
        if(r->left!=NULL){
            printf("%d",r->left);
            tree.push(r->left);
        }
        if(r->right!=NULL){
            printf("%d",r->right);
            tree.push(r->right);
        }
        tree.pop();
    }
     return a;
    }      
};

int main()
{
    Solution* a = new Solution();
    vector<int> b = {3,9,20,15,7};
    vector<int> c = {9,3,15,20,7};
    a->preorder = b;
    TreeNode* root = a->buildTree(b,c);
    a->PrintFromTopToBottom(root);
    return 0;
}

// unordered_map<int, int> map;

// TreeNode* buildTree2(int preL, int preR, int inL,int inR, vector<int>& preorder, vector<int>& inorder)
// {
//     if(preL > preR || inL > inR){
//         return NULL;
//     }

//     int middle = preorder[preL];
//     TreeNode* root = new TreeNode(middle);
//     auto it = map.find(middle);
//     int index = it->first;

//     root->left = buildTree2(preL + 1, preL + (index - inL), inL, index - 1, preorder, inorder);
//     root->right = buildTree2(preL + (index - inL) + 1, preR, index + 1, inR, preorder, inorder);
//     return root;
// }

// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
// {
//     int preLen = preorder.size();
//     int inLen = inorder.size();
    
//     for (int i = 0; i < inLen; i++)
//     {
//         map[i] = inorder[i];
//     }

//     return buildTree2(0, preLen - 1, 0, inLen - 1, preorder, inorder);
    
// }
