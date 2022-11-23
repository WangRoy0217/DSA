/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1,2], n = 1
Output: [1]

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr,*fir,*sec;
    ptr=new ListNode(0);
    ptr->next=head;
    fir=ptr;
    sec=ptr;
    for(int i=1;i<=n+1;i++)
        fir=fir->next;
    while(fir!=NULL){
        fir=fir->next;
        sec=sec->next;
    }
    sec->next=sec->next->next;

    return ptr->next;
        
    }
};