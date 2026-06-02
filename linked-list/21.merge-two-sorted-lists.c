/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
    int val;
     struct ListNode *next;
 };
//Linked List
//merge-two-sorted-lists
//Time Complexity: O(m + n) where m and n are the lengths of the two linked lists. We traverse both linked lists once.
//Space Complexity: O(1) since we are merging the two linked lists in place without using any additional data structures.
//Approach: We can use two pointers to traverse both linked lists simultaneously. We compare the values of the nodes pointed to by the two pointers and append the smaller value to the result linked list. We then move the pointer of the linked list from which we took the node to the next node. We repeat this process until we reach the end of one of the linked lists. After that, we can simply append the remaining nodes of the other linked list to the result linked list since they are already sorted. Finally, we return the head of the merged linked list.
#include <stdlib.h>
struct ListNode* ordins(struct ListNode * list,int x)
{
    struct ListNode* temp,*prev;
struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
newnode->val=x;
newnode->next=NULL;
if(list==NULL)
{
    list=newnode;
}
else if(list->val>x)
{
    newnode->next=list;
    list=newnode;
}
else{
    temp=list;
    while(temp->next!=NULL&&temp->val<=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->val>x)
    {
        newnode->next=prev->next;
        prev->next=newnode;

    }
    else if(temp->next==NULL)
    {
        temp->next=newnode;
    }
}
    return list;
}



struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* listm=NULL;
    while(list1!=NULL)
    {
        listm=ordins(listm,list1->val);
        list1=list1->next;
    }
    while(list2!=NULL)
    {
        listm=ordins(listm,list2->val);
        list2=list2->next;
    }
    return listm;
}
// @lc code=end

