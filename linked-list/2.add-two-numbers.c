/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//linked-list/math
//add-two-numbers
//Time Complexity: O(max(m, n)) where m and n are the lengths of the two linked lists. We traverse both linked lists once.
//Space Complexity: O(max(m, n)) since we are creating a new linked list to store the result, and in the worst case, the length of the result can be at most max(m, n) + 1 (if there is a carry at the end).
//Approach: We can use a while loop to traverse both linked lists simultaneously. We maintain a carry variable to keep track of any carry that may occur when adding the values of the nodes. For each pair of nodes, we calculate the sum of their values along with the carry. We then create a new node with the value of sum % 10 and update the carry to sum / 10. We append the new node to the result linked list. After the loop, if there is still a carry left, we create a new node with the value of carry and append it to the result linked list. Finally, we return the head of the result linked list.     
#include <stdlib.h>
#include <stdio.h>
struct ListNode {
    int val;
   struct ListNode *next;
  };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result=NULL,*tail=NULL;
    int carry=0,sum=0;
    while(l1!=NULL||l2!=NULL)
    {
    int x=(l1!=NULL)?l1->val:0;
    int y=(l2!=NULL)?l2->val:0;
    sum=x+y+carry;
    carry=sum/10;
    struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
    newnode->val=sum%10;
    newnode->next=NULL;
    if(result==NULL)
    {
        result=newnode;
        tail=result;
        
    }
    else{
       
       tail->next=newnode;
       tail=newnode;//very important to maintain tail in the end of the linked list also if while is used here exception is raised if only 1 element is there.
    }
    if(l1!=NULL)
    {
        l1=l1->next;
    }
    if(l2!=NULL)
    {
        l2=l2->next;
    }
    }
    if(carry>0)
    {
        struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
    newnode->val=carry;
    newnode->next=NULL;
    
    tail->next=newnode;

}
return result;
}
// @lc code=end

