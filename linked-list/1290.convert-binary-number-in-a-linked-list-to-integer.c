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
//Space Complexity: O(n) where n is the number of nodes in the linked list. We are using an array to store the binary digits, which requires additional space proportional to the number of nodes in the linked list.
//Approach: We can traverse the linked list and store the binary digits in an array. We then iterate through the array in reverse order, multiplying each binary digit by the corresponding power of 2 and summing the results to get the final integer value. Finally, we return the computed integer value.
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };    
int getDecimalValue(struct ListNode* head) {
    if(head==NULL)
    {
        return -1;
    }
    int* arr=(int*)malloc(31*sizeof(int));
    int n=0;
    struct ListNode *temp=head;
    while(temp!=NULL)
    {
        arr[n]=temp->val;
        n++;
        temp=temp->next;
    }
    int res=0,k=0;
    for(int i=n-1;i>=0;i--)
    {
        res+=arr[i]*pow(2,k);
        k++;
    }
    return res;
}
// @lc code=end

