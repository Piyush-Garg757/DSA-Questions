/*Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]
Explanation:

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]
Explanation:

Example 3:
Input: root = []
Output: []
Example 4:
Input: root = [1]
Output: [1]*/
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
    void postorder(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Iterative using 1 stack
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> st;
        while (!st.empty() || root != nullptr)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == nullptr)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && (temp == st.top()->right))
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    root = temp;
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)