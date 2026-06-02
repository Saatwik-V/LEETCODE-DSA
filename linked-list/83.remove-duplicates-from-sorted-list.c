/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
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
//remove-duplicates-from-sorted-list
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables.
//Approach: We can use a while loop to traverse the linked list. We compare the value of the current node with the value of the next node. If they are the same, we update the next pointer of the current node to skip the next node, effectively removing the duplicate node from the linked list. If they are different, we simply move to the next node. We continue this process until we reach the end of the linked list. Finally, we return the head of the modified linked list.
#include <stdio.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp=head,*prev=NULL;
    if(temp==NULL)
    {
        return prev;
    }
    while(temp->next!=NULL)//head may not be needed also
    {
        if(temp->val==temp->next->val)
        {
            
            temp->next=temp->next->next;

        }
        else{
        temp=temp->next;//here the else takes care that all the duplicates are deleted and then only temp is moved to next
        }
    }
    return head;
}

// @lc code=end

