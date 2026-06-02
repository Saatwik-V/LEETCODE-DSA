/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
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
//intersection-of-two-linked-lists
//Time Complexity: O(m + n) where m and n are the lengths of the two linked lists. In the worst case, we traverse both linked lists once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables.
//Approach: We can use two pointers to traverse both linked lists simultaneously. We initialize two pointers, temp1 and temp2, to the heads of the two linked lists. We then move both pointers one step at a time. If temp1 reaches the end of its linked list, we reset it to the head of the other linked list (headB). Similarly, if temp2 reaches the end of its linked list, we reset it to the head of the other linked list (headA). We continue this process until temp1 and temp2 point to the same node, which will be the intersection node. If there is no intersection, both pointers will eventually become NULL, and we can return NULL. Finally, we return the node pointed to by temp1 (or temp2) as the intersection node.
#include <stdio.h>
 struct ListNode {
     int val;
      struct ListNode *next;
 };
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL||headB==NULL)
    {
        return NULL;
    }
    struct ListNode * temp1=headA;
    struct ListNode *temp2=headB;
    while(temp1!=temp2)
    {
        temp1=(temp1==NULL)?headB:temp1->next;
        temp2=(temp2==NULL)?headA:temp2->next;

    }
    return temp1;
}
// @lc code=end

