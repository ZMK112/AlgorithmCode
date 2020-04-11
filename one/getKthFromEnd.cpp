#include <iostream>
#include <vector>
#include <string.h>
    
using namespace std;  
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    if (head == nullptr || k == 0)
    {
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = head;
    for (int i = 0; i < k - 1; i++)
    {
        if (p1->next != nullptr)
        {
            p1 = p1->next;
        }
    }
    while (p1->next != nullptr)
    {
        p1 =  p1->next;
        p2 = p2->next;
    }
    
    return p2;
}