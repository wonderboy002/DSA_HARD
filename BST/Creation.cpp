#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        right = left = NULL;
    }
};

Node *insertBST(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    if (root->data < data)
    {
        root->right = insertBST(root->right, data);
    }

    else
    {

        root->left = insertBST(root->left, data);
    }
    return root;
}

void createTree(Node *&root)
{
    int data;
    cout << "Enter data points";
    cin >> data;

    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    createTree(root);
    cout << "BST successfully created" << endl;
    inorder(root);
    return 0;
}