#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode *head1 = nullptr, *head2 = nullptr, *tmp, *p;
    if (!head)
    {
        return nullptr;
    }
    
    while (head)
    {
        if (head->val < x)
        {
            if (head1 == nullptr)
            {
                head1 = head;
                p = head1;
            }
            else
            {
                head1->next = head;
                head1 = head;
            }
            
        }
        else
        {
            if (head2 == nullptr)
            {
                head2 = head;
                tmp = head;
            }
            else
            {
                head2->next = head;
                head2 = head;
            }
        }
        head = head->next;
    }
    
    if (head1 != nullptr && head2 != nullptr)
    {
        head1->next = tmp;
        head2->next = nullptr;
    }
    else if(head1 == nullptr)
    {
        return tmp;
    }
    
    return p; 
}


int main()
{
    ListNode *root, *p;
    vector<int> nums = {1,1};
    root = new ListNode(nums[0]);
    p = root;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode* tmp = new ListNode(nums[i]);
        p->next = tmp;
        p = p->next;
    }
    partition(root,0);
    return 0;
}