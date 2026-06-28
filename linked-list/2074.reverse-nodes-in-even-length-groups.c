/*
 * @lc app=leetcode id=2074 lang=c
 *
 * [2074] Reverse Nodes in Even Length Groups
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
//reverse-nodes-in-even-length-groups
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once to count the number of nodes and then again to reverse the nodes in even length groups.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables. We are not using any additional data structures that grow with the input size.
//Approach: We can first count the number of nodes in the linked list and then traverse the linked list again to reverse the nodes in even length groups. We maintain a counter k to keep track of the current group size and a counter j to keep track of the number of nodes processed so far. For each group, if the group size k is odd, we simply move the pointers forward without reversing. If the group size k is even, we reverse the nodes in that group by updating the next pointers of the nodes. We also keep track of the previous node (prev) to connect the reversed group with the rest of the linked list. After processing all complete groups, we check if there are any remaining nodes and reverse them if their count is even. Finally, we return the head of the modified linked list.
#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    int node_count=0;
    int k=1,j=0;
    struct ListNode *prev=NULL,*curr=head,*right=NULL,*temp=head,*temp2=NULL,*temp3=NULL;
    while(temp!=NULL)
    {
        node_count++;
        temp=temp->next;
    }
    
    while(node_count-j>=k)
    {
        if(k%2!=0)
        {
            for(int i=0;i<k;i++)
            {
                prev=curr;
                curr=curr->next;
                j++;
            }
        }
        else{
            temp2=curr;
            temp3=prev;
            for(int i=0;i<k;i++)
            {
                temp2=temp2->next;
            }
            for(int i=0;i<k;i++)
            {
                j++;
                right=curr->next;
                if(i==0)
                {
                    curr->next=temp2;
                }
                else{
                    curr->next=prev;
                }
                prev=curr;
                curr=right;
                
            }
            temp3->next=prev;
            for(int i=0;i<k-1;i++)
            {
                prev=prev->next;//to place prev before current
            }
        }
        k++;
    } 
    j=0;
    temp=curr;
    while(temp!=NULL)
    {
        j++;
        temp=temp->next;
    } 
    if(j%2!=0||j==0)
    {
        return head;
    } 
    else{
        temp2=curr;
        temp3=prev;
        for(int i=0;i<j;i++)
        {
            right=curr->next;
                if(i==0)
                {
                    curr->next=NULL;
                }
                else{
                    curr->next=prev;
                }
                prev=curr;
                curr=right;
                   //the line causing tle 
        }
        temp3->next=prev;
        
        
    }
    return head;
    
}
// @lc code=end

