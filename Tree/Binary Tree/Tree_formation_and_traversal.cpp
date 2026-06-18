#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;

    node(int val)
    {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};
void preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    // TC - O(n)  SC - O(n)
}
void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    // TC - O(n)  SC - O(n)
}
void postorder(node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    // TC - O(n)  SC - O(n)
}
void bfs(node *root)
{
    if (root == nullptr)
        return;
    vector<vector<int>> ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            node *a = q.front();
            q.pop();
            if (a->left)
                q.push(a->left);
            if (a->right)
                q.push(a->right);
            v[i] = a->data;
        }
        ans.push_back(v);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    // TC - O(n)  SC - O(n)
}
void iterative_preorder(node *root)
{
    if (root == nullptr)
        return;
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *a = st.top();
        st.pop();
        cout << a->data << " ";
        if (a->right)
            st.push(a->right);
        if (a->left)
            st.push(a->left);
    }
    // TC - O(n)  SC - O(n)
}
void iterative_inorder(node *root)
{
    if (root == nullptr)
        return;
    stack<node *> st;
    while (true)
    {
        if (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
    // TC - O(n)  SC - O(n)
}
void iterative_postorder_using_2_stack(node *root)
{
    if (root == nullptr)
        return;
    stack<node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        node *a = st1.top();
        st1.pop();
        st2.push(a);
        if (a->left)
            st1.push(a->left);
        if (a->right)
            st1.push(a->right);
    }
    while (!st2.empty())
    {
        node *a = st2.top();
        st2.pop();
        cout << a->data << " ";
    }
    // TC - O(n)  SC - O(n)
}
int main()
{
    node *root = new node(2);
    root->left = new node(3);
    root->right = new node(4);
    root->left->right = new node(5);
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    bfs(root); // this is also called level order traversal;
    iterative_preorder(root);
    cout << "\n";
    iterative_inorder(root);
    cout << "\n";
    iterative_postorder_using_2_stack(root);
    cout << "\n";
    return 0;
}