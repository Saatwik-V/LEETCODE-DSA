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
//Time Complexity: O(n) where n is the number of nodes in the binary tree.
//Space Complexity: O(n) where n is the number of nodes in the binary tree. The space is used for the stack to store the nodes during the traversal.
//Approach: We can use an iterative approach with a stack to flatten the binary tree into a linked list. We start by pushing the root node onto the stack. Then, we enter a loop that continues until the stack is empty. In each iteration, we pop a node from the stack and check its right and left children. If the right child exists, we push it onto the stack. If the left child exists, we push it onto the stack as well. After processing the current node, we set its right child to point to the next node in the stack (if any) and set its left child to NULL. This effectively flattens the binary tree into a linked list in-place, following the preorder traversal order. Finally, we return the modified root of the binary tree, which now represents the head of the flattened linked list.
#include<stdio.h>
  struct TreeNode {
      int val;  
    struct TreeNode *left;
    struct TreeNode *right;
  };
void flatten(struct TreeNode* root) {
    if(root==NULL)
    {
        return;
    }
    struct TreeNode *stack[2001];
    int top=-1;
    stack[++top]=root;
    while(top!=-1)
    {
        struct TreeNode *curr=stack[top--];
        if(curr->right!=NULL)
        {
            stack[++top]=curr->right;
        }
        if(curr->left!=NULL)
        {
            stack[++top]=curr->left;
        }
        if(top!=-1)
        {
            curr->right=stack[top];
        }
        curr->left=NULL;
    }
    return;
    
}
// @lc code=end

