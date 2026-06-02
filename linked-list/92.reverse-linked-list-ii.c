/*
 * @lc app=leetcode id=92 lang=c
 *
 * [92] Reverse Linked List II
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
//reverse-linked-list-ii
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables.
//Approach: We can use three pointers to reverse the linked list iteratively. We initialize prev to NULL, temp to the head of the linked list, and after to NULL. We also initialize two additional pointers, tail and before, to keep track of the tail of the reversed sublist and the node before the left position, respectively. We first traverse the linked list until we reach the left position, updating the before pointer to point to the node before the left position and the tail pointer to point to the node at the left position. We then continue traversing the linked list until we reach the right position, reversing the nodes in the process. After we have reversed the sublist, we update the next pointer of the before node to point to the new head of the reversed sublist (prev) and the next pointer of the tail node to point to the node after the right position (temp). Finally, we return the head of the modified linked list, which is either the original head or the new head of the reversed sublist depending on whether the left position is the head of the linked list or not.
#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left==right)
    {
        return head;
    }
    int i=1;
    struct ListNode* temp=head, *prev=NULL, *after=NULL, *tail=NULL, *before=NULL;
    while(i!=left)
    {
        before=temp;
        temp=temp->next;
        i++;
    }
    tail=temp;
    
    while(i<=right)
    {
        after=temp->next;
        temp->next=prev;
        prev=temp;
        temp=after;
        i++;
    }
    if(before)
    {
        before->next=prev;
    }
    else
    {
        head=prev;
    }
    tail->next=temp;
    return head;
}
// @lc code=end

