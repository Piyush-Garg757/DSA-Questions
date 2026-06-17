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
int main()
{
    node *root = new node(2);
    root->left = new node(3);
    root->right = new node(4);
    root->left->right = new node(5);
    return 0;
}