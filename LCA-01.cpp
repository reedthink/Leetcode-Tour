#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;
struct Node
{
    Node *left, *right;
    int key;
    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

Node *findLCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->key == n1 || root->key == n2)
    {
        return root;
    }

    auto left_lca = findLCA(root->left, n1, n2);
    auto right_lca = findLCA(root->right, n1, n2);

    //左子树存在一个给定节点，右子树存在另一个给定节点，根为LCA

    if (left_lca && right_lca)
        return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
    
    return 0;
}