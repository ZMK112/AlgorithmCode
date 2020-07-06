#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void heapify(deque<ListNode*>& list, int lens, int index)
{
    if(index >= lens) return;
    int left = 2 * index + 1;
    if(left >= lens) return;
    int maxIndex = left + 1 < lens && list[left + 1]->val < list[left]->val ? left + 1 : left;
    maxIndex =  list[maxIndex]->val < list[index]->val ? maxIndex : index;
    if(maxIndex == index) return;
    swap(list[maxIndex], list[index]);
    heapify(list, lens, maxIndex);    
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.empty()) return nullptr;

    deque<ListNode*> queue;

    for (int i = 0; i < lists.size(); i++)
    {
        ListNode* p = lists[i];
        while (p)
        {
            queue.push_back(p);
            p = p->next;
        }
    }

    for (int i = queue.size()/2 - 1; i >= 0; i--)
    {
        heapify(queue, queue.size(), i);
    }
    
    ListNode *ph = nullptr, *pr = nullptr;

    while (queue.size() > 0)
    {
        ListNode* p = new ListNode(queue[0]->val);
        if(!ph){
            ph = p;
        }
        else
        {
            pr->next = p;
        }
        pr = p;
        queue.pop_front();
        if (!queue.empty())
        {
            heapify(queue, queue.size(), 0);
        }    
    }
    return ph;
}
// void heapify(vector<ListNode*>& list, int lens, int index)
// {
//     if (index > lens)
//     {
//         return;
//     }
    
//     int left = index * 2 + 1;

//     if (left > lens)
//     {
//         return;
//     }
    
//     int maxIndex = left + 1 < lens && list[left + 1]->val < list[left]->val ? left + 1 : left;
//     maxIndex = list[maxIndex]->val > list[index]->val ? index : maxIndex;
//     if (maxIndex == index)
//     {
//         return;
//     }
//     swap(list[maxIndex], list[index]);
//     heapify(list, lens, maxIndex);
// }

// ListNode* mergeKLists(vector<ListNode*>& list)
// {
//     vector<ListNode*> node;
//     for (int i = 0; i < list.size(); i++)
//     {   
//         ListNode* p = list[i];
//         while (p)
//         {
//             node.push_back(p);
//             p = p->next;
//         }
//     }
    
//     int lens = node.size();
//     for (int i = lens/2 - 1; i >= 0; i--)
//     {
//         heapify(node, lens, i);
//     }

//     ListNode *ph = nullptr, *pr = nullptr;

//     while (node.size() > 0)
//     {
//         ListNode* p = new ListNode(node[0]->val);
//         int length = node.size();
//         if (ph == nullptr)
//         {
//             ph = p;
//         }
//         else
//         {
//             pr->next = p;
//         }
//         ph->next = pr;
//         node[0] = node[0]->next;
//         if (!node[0])
//         {
//             swap(node[0], node[length - 1]);
//             node.pop_back();
//         }
//         if (!node.empty())
//         {
//             heapify(node, length, 0);
//         }
//     }

//     return node[0];
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
void heapify(vector<ListNode*>& list, int lens, int index)
{
    if (index > lens)
    {
        return;
    }

    int left = index * 2 + 1;

    if (left >= lens)
    {
        return;
    }

    int maxIndex = (left + 1 < lens) && list[left + 1]->val < list[left]->val ? left + 1 : left;

    maxIndex = list[maxIndex]->val > list[index]->val ? index : maxIndex;
    if (maxIndex != index)
    {
        swap(list[maxIndex], list[index]);
        heapify(list, lens, maxIndex);
    }
}

ListNode* mergeKLists(vector<ListNode*>& list)
{
    vector<ListNode*> node;
    for (int i = 0; i < list.size(); i++)
    {   
        ListNode* p = list[i];
        while (p)
        {
            node.push_back(p);
            p = p->next;
        }
    }
    
    for (int i = node.size()/2 - 1; i >= 0; i--)
    {
        heapify(node, node.size(), i);
    }

    ListNode *ph = nullptr, *pr = nullptr;

    while (node.size() > 0)
    {
        ListNode* p = new ListNode(node[0]->val);
        
        if (ph == nullptr)
        {
            ph = p;
        }
        else
        {
            pr->next = p;
        }
        pr = p;
        swap(node[0], node[node.size() - 1]);
        node.pop_back();
        if (!node.empty())
        {
            heapify(node, node.size(), 0);
        }
    }

    return ph;
}
};