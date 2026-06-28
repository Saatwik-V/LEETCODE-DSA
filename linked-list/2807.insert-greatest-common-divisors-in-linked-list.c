/*
 * @lc app=leetcode id=2807 lang=c
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
//insert-greatest-common-divisors-in-linked-list
//Time Complexity: O(n * log(max(a, b))) where n is the number of nodes in the linked list and max(a, b) is the maximum value of the two adjacent nodes. We traverse the linked list once and for each pair of adjacent nodes, we calculate their GCD using the Euclidean algorithm, which takes O(log(max(a, b))) time.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables. We are not using any additional data structures that grow with the input size.
//Approach: We can traverse the linked list while keeping track of the previous node (prev) and the current node (temp). For each pair of adjacent nodes, we calculate their GCD using the Euclidean algorithm. We then create a new node with the GCD value and insert it between the two nodes by updating the next pointers. We continue this process until we reach the end of the linked list. Finally, we return the head of the modified linked list. This approach ensures that we only traverse the linked list a constant number of times, resulting in O(n * log(max(a, b))) time complexity.
#include <stdio.h>
struct ListNode {
     int val;   
        struct ListNode *next;
};
 int gcd(int m,int n)
 {
    if(n==0)
    {
        return m;
    }
   
    return gcd(n,m%n);
    
 }
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct ListNode * prev=head,*temp=head->next;
    int value;
    while(temp!=NULL)
    {
        value=gcd(prev->val,temp->val);
        struct ListNode* mid=(struct ListNode*)malloc(sizeof(struct ListNode));
        mid->val=value;
        prev->next=mid;
        mid->next=temp;
        prev=temp;
        temp=temp->next;
    }
    return head;
}
// @lc code=end

