//Linked List
//rotate-list
//Time Complexity: O(n) where n is the number of nodes in the linked list. We traverse the linked list once to count the number of nodes and then again to find the new head and tail of the rotated list.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables. We are not using any additional data structures that grow with the input size.
//Approach: We can first count the number of nodes in the linked list. Then, we can connect the tail of the linked list to the head to form a circular linked list. Next, we can find the new head and tail of the rotated list by moving (n - (k % n)) steps from the head of the list. Finally, we can break the circular linked list by setting the next pointer of the new tail to NULL and return the new head of the rotated list. This approach ensures that we only traverse the linked list a constant number of times, resulting in O(n) time complexity. 

#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;        
    };
    
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int n=0;
    if(head==NULL)
    {
        return head;
    }
    struct ListNode *temp=head,*prev=NULL;
    while(temp->next!=NULL){
        n++;
        temp=temp->next;
    }
    n++;
    temp->next=head;
    for(int i=0;i<n-(k%n);i++)
    {
        prev=head;
        head=head->next;
    }
    prev->next=NULL;
    return head;
    
}