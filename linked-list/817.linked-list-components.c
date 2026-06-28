 //Linked List
//num-components
//Time Complexity: O(n*m) where n is the number of nodes in the linked list and m is the size of the nums array. In the worst case, we may have to check each node against all elements in nums.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the count of connected components and the connected flag. We are not using any additional data structures that grow with the input size.
//Approach: We can traverse the linked list and for each node, we check if its value is present in the nums array using a helper function search. If the value is found, we continue traversing the linked list until we reach a node whose value is not present in nums. We keep track of whether we are currently in a connected component using a flag connected. If we reach a node whose value is not present in nums and we were previously in a connected component (connected is 1), we increment the count of connected components and reset the connected flag to 0. We continue this process until we reach the end of the linked list. Finally, we return the count of connected components found in the linked list.   
#include <stdbool.h>
#include <stdio.h>
struct ListNode {   
        int val;
        struct ListNode *next;
    };
 
 bool search(int k,int* nums,int numsSize)
  { 
    for(int i=0;i<numsSize;i++) 
  { 
        if(nums[i]==k) 
        { 
        return true; 
        } 
  } 
  return false; 
  }
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    if(head==NULL){
        return -1;
    }
    
    int count=0,connected=0;
    struct ListNode *temp=head;
    while(temp!=NULL)
    {
        while(search(temp->val,nums,numsSize))
        {
            temp=temp->next;
            if(temp==NULL)
            {
                count ++;
                return count;
            }
            if(connected==0)
            {
                connected=1;
            }
        }
        if(connected==1)
        {
            count++;
            connected=0;
        }
        temp=temp->next;

    }
    return count;
}