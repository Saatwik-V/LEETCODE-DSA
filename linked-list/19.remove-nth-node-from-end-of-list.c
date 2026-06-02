/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
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
//remove-nth-node-from-end-of-list
//Time Complexity: O(n) where n is the number of nodes in the linked list.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables.
//Approach: We can first traverse the linked list to find the total number of nodes. Then, we can calculate the position of the node to be removed from the beginning of the list, which is (total nodes - n). We can then traverse the list again to reach the node just before the node to be removed and update its next pointer to skip the node to be removed. If the node to be removed is the head of the list, we can simply update the head pointer to the next node. Finally, we return the head of the modified linked list.
#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
  };
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode * temp=head,*prev=NULL,*temp1=head;
    int i=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    for(int j=0;j<(i-n);j++)
    {
        prev=temp1;
        temp1=temp1->next;
    }
    if(temp==temp1&&prev==NULL)
    {
        head=NULL;
    }
    else {
    if(temp1->next==NULL)
    {
        prev->next=NULL;
        
    }
    else if(temp1==head){
        
        head=head->next;
    }
    else{
        prev->next=temp1->next;
    }
    }
   return head; 
}
// @lc code=end

