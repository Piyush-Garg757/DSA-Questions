/*Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1*/

// My first approach - isoptimal asymptotically but traversing tree 2 times and maintaining 2 arrays and the iterating through them    but did it myself
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool solve(TreeNode *root, TreeNode *node, vector<TreeNode *> &a)
    {
        if (!root)
            return false;
        a.push_back(root);
        if (root == node)
            return true;
        if (solve(root->left, node, a))
            return true;
        if (solve(root->right, node, a))
            return true;
        a.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_to_p, path_to_q;
        solve(root, p, path_to_p);
        solve(root, q, path_to_q);
        int i = 0, j = 0, n = path_to_p.size(), m = path_to_q.size();
        TreeNode *a = nullptr;
        while (i < n && j < m)
        {
            if (path_to_p[i] == path_to_q[j])
                a = path_to_p[i];
            i++;
            j++;
        }
        return a;
    }
};
// TC - O(n)  SC - O(h)

// Most Optimal sol
