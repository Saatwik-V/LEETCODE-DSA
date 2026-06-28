/*
 * @lc app=leetcode id=1669 lang=c
 *
 * [1669] Merge In Between Linked Lists
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
//merge-in-between-linked-lists
//Time Complexity: O(n + m) where n is the number of nodes in list1 and m is the number of nodes in list2. We traverse both linked lists once to find the appropriate nodes to connect, leading to O(n + m) time complexity.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables. We are not using any additional data structures that grow with the input size.
//Approach: We can first traverse list2 to find the last node (end2). Then, we traverse list1 to find the nodes at positions a-1 (A) and b (B). We update the next pointer of node A to point to the head of list2 (start2) and the next pointer of end2 to point to node B. This effectively merges list2 into list1 between the nodes at positions a and b. Finally, we return the head of the modified list1. This approach ensures that we only traverse each linked list a constant number of times, resulting in O(n + m) time complexity.

#include<stdio.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *start2=list2,*end2=list2;
    while(end2->next!=NULL)
    {
        end2=end2->next;
    }
    struct ListNode* A=list1,*B=list1;
    for(int i=0;i<a-1;i++)
    {
        A=A->next;
    }
    for(int i=0;i<=b;i++)
    {
        B=B->next;
    }
    A->next=start2;
    end2->next=B;
    return list1;


}

// @lc code=end

