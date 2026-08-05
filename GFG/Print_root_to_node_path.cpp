/*kii to target node given hoga     root se uss tak ka path return karna hai */
class Solution
{
public:
    bool findPath(Node *root, int target, vector<int> &path)
    {
        if (!root)
            return false;
        path.push_back(root->data);
        if (root->data == target)
            return true;
        if (findPath(root->left, target, path) ||
            findPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }

    vector<int> rootToNodePath(Node *root, int target)
    {
        vector<int> path;
        findPath(root, target, path);
        return path;
    }
};
// TC - O(n)  SC - O(h)