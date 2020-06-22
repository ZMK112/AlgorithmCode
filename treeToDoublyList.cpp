#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int x):val(x),left(NULL),right(NULL){}
};

void listTree(Node* root, Node*& head, Node*& tail)
{
    if (root == nullptr)
    {
        return;
    }
    
    Node *Lhead, *Ltail, *Rhead, *Rtail;
    Lhead = root;

    if (root->left != nullptr)
    {
        listTree(root->left, Lhead, Ltail);
        root->left = Ltail;
        Ltail->right = root;
    }
    
    Rtail = root;

    if (root->right != nullptr)
    {
        listTree(root->right, Rhead, Rtail);
        root->right = Rhead;
        Rhead->left = root;
    }
    head = Lhead;
    tail = Rtail;
}


Node* treeToDoublyList(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    
    Node *head, *tail;
    listTree(root, head, tail);
    head->left = tail;
    tail->right = head;
    return head;
}


// void convertNode(Node* point, Node** nodeList)
// {
//     if (point == nullptr)
//     {
//         return;
//     }

//     Node* curPoint = point;

//     if (curPoint->left != nullptr)
//     {
//         convertNode(curPoint->left, nodeList);
//     }

//     curPoint->left = *nodeList;

//     if (*nodeList != nullptr)
//     {
//         (*nodeList)->right = curPoint;
//     }

//     *nodeList = curPoint;

//     if (curPoint->right != nullptr)
//     {
//         convertNode(curPoint->right, nodeList);
//     }
// }

// Node* treeToDoublyList(Node* root) {
//     Node* list = nullptr;
//     convertNode(root, &list);
//     Node* headList = list;
//     while (headList != nullptr && headList->left != nullptr)
//     {
//         headList = headList->left;
//     }
//     return headList;
// }


