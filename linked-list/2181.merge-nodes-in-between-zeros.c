/*
 * @lc app=leetcode id=2181 lang=c
 *
 * [2181] Merge Nodes in Between Zeros
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//Linked List
//merge-nodes-in-between-zeros
//Time Complexity: O(n) where n is the number of nodes in the linked list.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables.
//Approach: We can traverse the linked list and for each node, we check if its value is not zero. If it is not zero, we add its value to the previous node's value and move to the next node. If it is zero, we skip the current node and move to the next node. We continue this process until we reach the end of the linked list. Finally, we return the head of the modified linked list, which contains the merged values in between zeros.
#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* mergeNodes(struct ListNode* head) {
    head=head->next;
    struct ListNode* temp=head->next,*prev=head;
    while(temp->next!=NULL)
    {
        if(temp->val!=0)
        {
            prev->val+=temp->val;
            temp=temp->next;
            prev->next=temp;
        }
        else{
            temp=temp->next;
            prev->next=temp;
            prev=prev->next;
            temp=temp->next;//to keep temp after prev
        }
    }
    prev->next=NULL;
    return head;
}
// @lc code=end

