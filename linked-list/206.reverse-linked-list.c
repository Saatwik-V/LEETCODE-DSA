/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Linked List
//reverse-linked-list
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables.
//Approach: We can use three pointers to reverse the linked list iteratively. We initialize prev to NULL, curr to the head of the linked list, and after to NULL. We then iterate through the linked list until curr becomes NULL. In each iteration, we store the next node of curr in after, update the next pointer of curr to point to prev, move prev to curr, and move curr to after. This effectively reverses the linked list as we go through it. Finally, we return prev as the new head of the reversed linked list since curr will be NULL at the end of the loop and prev will be pointing to the last node of the original linked list, which is the new head of the reversed linked list.     
#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode * prev=NULL,*curr=head,*after=NULL;
    while(curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    return prev;
}
// @lc code=end

