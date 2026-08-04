/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	vector<int> leftView(Node *root) {
		// code here
		if (root == nullptr)
			return {};
		queue<Node *> q;
		q.push(root);
		vector<int> ans;
		while (!q.empty())
			{
			int size = q.size();
			int a = 1;
			for (int i = 0; i < size; i++)
				{
				Node *node = q.front();
				if (a == 1)
					{
					ans.push_back(node->data);
					a = 0;
				}
				q.pop();
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return ans;
	}
};
