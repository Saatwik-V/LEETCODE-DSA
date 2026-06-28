/*
 * @lc app=leetcode id=817 lang=c
 *
 * [817] Linked List Components
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
//linked-list-components    
//Time Complexity: O(n + m) where n is the number of nodes in the linked list and m is the size of the nums array. We traverse the linked list once and check each node's value against the nums array using a frequency array, leading to O(n + m) time complexity.
//Space Complexity: O(1) since we are using a fixed-size frequency array of size 10001 to store the presence of values in nums. This does not grow with the input size, so the space complexity is constant.
//Approach: We can use a frequency array to store the presence of values in the nums array. We initialize a frequency array of size 10001 (to accommodate the maximum possible value of node values) and set the indices corresponding to the values in nums to 1. We then traverse the linked list and for each node, we check if its value is present in the frequency array. If it is present, we increment the count of connected components and continue traversing the linked list until we reach a node whose value is not present in the frequency array.
#include<stdio.h>
#include<stdbool.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int present[10001]={0},count=0;
    for(int i=0;i<numsSize;i++)
    {
        present[nums[i]]=1;
    }
    struct ListNode *temp=head;
    while(temp!=NULL)
    {
        if(present[temp->val]==1)
        {
            count++;
            while(temp!=NULL&&present[temp->val]==1)
            {
                temp=temp->next;
            }
        }
        else{
            temp=temp->next;
        }
    }
    return count;
}
// @lc code=end

