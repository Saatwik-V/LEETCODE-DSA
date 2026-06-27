/*
 * @lc app=leetcode id=1290 lang=c
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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
//convert-binary-number-in-a-linked-list-to-integer
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once to convert the binary number to an integer.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables
//Approach: We can traverse the linked list and for each node, we left shift the current result by 1 (equivalent to multiplying by 2) and then add the value of the current node (0 or 1) to the result. This effectively builds the integer value as we traverse the linked list. Finally, we return the computed integer value.
#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };    
int getDecimalValue(struct ListNode* head) {
    int res=0;
    while(head!=NULL)
    {
        res=res<<1|head->val;
        head=head->next;
    }
    return res;
    
}
// @lc code=end

