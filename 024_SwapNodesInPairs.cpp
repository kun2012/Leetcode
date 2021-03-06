/****************************************************************
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.
****************************************************************/
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode tmp(0);
        ListNode* ah = &tmp;
        ListNode *pre = ah, *f = head, *s = head->next;
        while(true) {
            f->next = s->next;
            s->next = f;
            pre->next = s;
            
            if (f->next == NULL) break;
            if (f->next->next == NULL) break;
            s = f->next->next;
            pre = f;
            f = f->next;
        }
        return ah->next;
    }
};