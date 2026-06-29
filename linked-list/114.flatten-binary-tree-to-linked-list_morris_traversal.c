/*
 * @lc app=leetcode id=114 lang=c
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//Linked List
//flatten binary tree to linked list
//Time Complexity:O(n) where n is the number of nodes in the binary tree. We traverse each node once during the depth-first search (DFS) traversal, leading to O(n) time complexity.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and intermediate variables. We are not using any additional data structures that grow with the input size.
//Approach: We can use the Morris traversal technique to flatten the binary tree into a linked list. We start from the root node and iterate through the tree using a while loop. For each node, if it has a left child, we find the rightmost node of the left subtree (predecessor) and connect it to the right child of the current node. We then move the left child to the right and set the left child to NULL. We continue this process until we reach the end of the tree. This approach allows us to flatten the binary tree in-place without using any additional space for recursion or a stack, resulting in O(1) space complexity. Finally, we return the modified root of the binary tree, which now represents the head of the flattened linked list.

#include<stdio.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
     struct TreeNode *right;
 };
void flatten(struct TreeNode* root) {\
    
    struct TreeNode* curr=root;
    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            struct TreeNode *pre=curr->left;
            while(pre->right!=NULL)
            {
                pre=pre->right;
            }
            pre->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}
// @lc code=end

