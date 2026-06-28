/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
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
//swap-nodes-in-pairs
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once, swapping pairs of nodes as we go.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables. We are not using any additional data structures that grow with the input size.  
//Approach: We can use two pointers to traverse the linked list and swap pairs of nodes. We initialize two pointers, temp1 and temp2, to the first and second nodes of the linked list, respectively. We also keep track of the previous node (prev) to connect the swapped pairs. In each iteration, we swap the nodes pointed to by temp1 and temp2 by updating their next pointers. After swapping, we move the pointers forward to the next pair of nodes. We continue this process until we reach the end of the linked list. Finally, we return the new head of the linked list, which is either the original head or the new head after swapping the first pair of nodes.        
#include<stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode *temp1=head,*temp2=head->next,*prev=head;
    while(temp2!=NULL)//temp1!=NULL&&temp1->next!=NULL
    {
        temp1->next=temp2->next;
        temp2->next=temp1;
        if(temp1==head)
        {
            head=temp2;
        }
        else{
            prev->next=temp2;
        }
        if(temp1->next==NULL)
        {
            return head;
        }
        prev=temp1;
        temp1=temp1->next;
        temp2=temp1->next;
    }
    return head;
}
// @lc code=end

