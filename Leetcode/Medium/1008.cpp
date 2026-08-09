/*Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *solve(vector<int> &pre, int pre_start, int pre_end)
    {
        if (pre_start > pre_end)
            return nullptr;
        TreeNode *root = new TreeNode(pre[pre_start]);
        int i = pre_start + 1;
        while (i <= pre_end && pre[i] < root->val)
            i++;
        root->left = solve(pre, pre_start + 1, i - 1);
        root->right = solve(pre, i, pre_end);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        TreeNode *root = solve(pre, 0, pre.size() - 1);
        return root;
    }
};
// TC - O(n)  SC - O(n)