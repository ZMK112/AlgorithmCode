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

int getLens(ListNode* head)
{
    int lens = 0;
    while (head)
    {
        lens++;
        head = head->next;
    }
    return lens;
}

ListNode* forward(ListNode* head, int lens)
{
    while (head && lens)
    {
        head = head->next;
        lens--;
    }
    return head;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lensA = getLens(headA);
    int lensB = getLens(headB);

    if (lensA < lensB)
    {
        headB = forward(headB, lensB - lensA);
    }
    else
    {
        headA = forward(headA, lensA - lensB);
    }
    
    while (headA && headB)
    {
        if(headA == headB){
            return headA;
        }
        else
        {
            headA = headA->next;
            headB = headB->next;
        }
    }
    return nullptr;
}