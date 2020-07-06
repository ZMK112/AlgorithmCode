#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Listnode{
    int val;
    Listnode* next;
};

void add_tail(Listnode* &head, int value)
{
    Listnode* newNode = new Listnode();
    newNode->val = value;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        Listnode* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

vector<int> reversePrint(Listnode* head)
{
    stack<Listnode*> nodes;
    Listnode* p = head;
    while (p != nullptr)
    {
        nodes.push(p);
        p = p->next;
    }
    while (!nodes.empty())
    {
        p = nodes.top();
        printf("%d\t",p->val);
        nodes.pop();
    }
    
}


int main()
{
    Listnode* head =NULL;
    add_tail(head, 10);
    if (head != NULL)
    {
        cout << head->val << endl; 
    }
    else
    {
        cout << "head is null"<<endl;
    }
    return 0;    
}