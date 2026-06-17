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
    return 0;
}