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
//Time Complexity: O(n) where n is the number of nodes in the binary tree. We traverse each node once during the depth-first search (DFS) traversal, leading to O(n) time complexity.
//Space Complexity: O(h) where h is the height of the binary tree. In the worst case, the recursion stack can go up to the height of the tree, leading to O(h) space complexity. In the average case, the space complexity is O(log n) for a balanced binary tree, where h is the height of the tree. In the worst case, for a skewed binary tree, the height can be equal to the number of nodes, leading to O(n) space complexity.
//Approach: We can use a depth-first search (DFS) traversal to flatten the  binary tree into a linked list. We start from the right subtree and then move to the left subtree, ensuring that we process the right subtree first. We maintain a pointer (prev) to keep track of the previously processed node. For each node, we set its right child to point to the prev node and set its left child to NULL. We then update the prev pointer to the current node. This way, we effectively flatten the binary tree into a linked list in-place, following the preorder traversal order. Finally, we return the modified root of the binary tree, which now represents the head of the flattened linked list.   

#include<stdio.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
struct TreeNode *prev=NULL;
 void dfs(struct TreeNode* root)
 {
    if(root==NULL)
    {
        return;
    }
    dfs(root->right);
    dfs(root->left);
    root->right=prev;
    root->left=NULL;
    prev=root;
 }
void flatten(struct TreeNode* root) {
    
    
    prev=NULL;//leetcode uses same global state to next test case 
    dfs(root);

    
}
// @lc code=end

