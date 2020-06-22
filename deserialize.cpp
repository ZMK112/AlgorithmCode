#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <queue>

#include <fstream>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void solve(ostringstream& out, TreeNode* root)
{
    if (!root)
    {   
        out<<"null ";
        return;
    }
    out<< root->val << " ";
    solve(out, root->left);
    solve(out, root->right);
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    ostringstream out;
    solve(out, root);
    return out.str();
}

// Decodes your encoded data to tree.

TreeNode* solve2(istringstream& is)
{
    string str;
    is>>str;
    if (str == "null")
    {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(stoi(str));
    root->left = solve2(is);
    root->right = solve2(is);
    return root;
}

TreeNode* deserialize(string data) {
    if (!data.length())
    {
        return nullptr;
    }
    istringstream is(data);
    TreeNode* root = solve2(is);
    return root;
}

TreeNode* solve2(string data, int index)
{
    TreeNode* root;
    if (index >= data.length())
    {
        return root;
    }
    root = new TreeNode(data[index] - '0');//没有办法处理null，还涉及char和string之间的转换
    root->left = solve2(data, index * 2 + 1);
    root->right = solve2(data, index * 2 + 2);
    return root;
}

TreeNode* deserialize(string data) {
    if (!data.length())
    {
        return nullptr;
    }
    TreeNode* root = solve2(data, 0);
    return root;
}