#include <iostream>
#include <vector>
#include <string.h>
    
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ListNode* reverseList(ListNode* head) {
//     ListNode* p = head;
//     ListNode* p_pre = nullptr;
//     ListNode* p_head = nullptr;
//     while ( p != nullptr)
//     {
//         if (p->next == nullptr)
//             break;
//         ListNode* p_next = p->next;
//         p->next = p_pre;
//         p_pre = p;
//         p = p_next;
//     }
//     return p;
// }

ListNode* reverseList(ListNode* head) {
    ListNode* p = head;
    ListNode* p_pre = nullptr;
    ListNode* p_head = nullptr;
    while (p != nullptr)
    {
        if(p->next == nullptr){
            p_head = p;
        }
        ListNode* p_next = p->next;
        p->next = p_pre;
        p_pre = p;
        p = p_next;
    }
    return p_head;
}