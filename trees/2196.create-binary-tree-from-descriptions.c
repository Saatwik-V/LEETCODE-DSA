/*
 * @lc app=leetcode id=2196 lang=c
 *
 * [2196] Create Binary Tree From Descriptions
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

 // Definition for a binary tree node.
 //tree
//Time Complexity: O(n) where n is the number of descriptions. We iterate through the descriptions three times: once to create the nodes, once to connect the nodes, and once to find the root. Each of these steps takes O(n) time.
//Space Complexity: O(n) where n is the number of descriptions. We use an array of size 100001 to store the pointers to the tree nodes, and another array of size 100001 to keep track of which nodes are children. In the worst case, if all nodes are unique, we will have n nodes in the tree, leading to O(n) space complexity.
 //Approach: We can use a hash map (or an array in this case, since the values are constrained) to store the pointers to the tree nodes. We iterate through the descriptions to create the nodes and store them in the map. Then we iterate through the descriptions again to connect the nodes according to the parent-child relationships specified. Finally, we iterate through the descriptions one last time to find the root node, which is the node that is not a child of any other node. We return the root of the constructed binary tree.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
  struct TreeNode {
     int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 

struct TreeNode* createNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {

    // Max value constraint = 1e5
    struct TreeNode* map[100001] = {NULL};
    bool isChild[100001] = {false};

    // Step 1: create nodes
    for(int i = 0; i < descriptionsSize; i++)
    {
        int parent = descriptions[i][0];
        int child = descriptions[i][1];

        if(map[parent] == NULL)
            map[parent] = createNode(parent);

        if(map[child] == NULL)
            map[child] = createNode(child);
    }

    // Step 2: connect nodes
    for(int i = 0; i < descriptionsSize; i++)
    {
        int parent = descriptions[i][0];
        int child = descriptions[i][1];
        int isLeft = descriptions[i][2];

        if(isLeft == 1)
            map[parent]->left = map[child];
        else
            map[parent]->right = map[child];

        isChild[child] = true;
    }

    // Step 3: find root
    struct TreeNode* root = NULL;

    for(int i = 0; i < descriptionsSize; i++)
    {
        int parent = descriptions[i][0];
        if(!isChild[parent])
        {
            root = map[parent];
            break;
        }
    }

    return root;
}
// @lc code=end

