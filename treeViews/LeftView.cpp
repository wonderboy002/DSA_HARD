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
        this->left = this->right = NULL;
    }
};
Node *create_tree()
{
    int data;
    cout << "Enter data : " << endl;
    cin >> data;

    // base case
    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    // node for which left and right subtrees are visited is returned
    cout << "Enter data for left child of " << root->data << endl;
    root->left = create_tree();

    cout << "Enter data for right child of " << root->data << endl;
    root->right = create_tree();

    return root;
}

void printLeftView(Node *root,int level,int &global){
    if (!root){
        return;
    }

    else if (level==global){
        cout<<root->data<<" ";
        global++;
    }

    printLeftView(root->left,level+1,global);
    printLeftView(root->right,level+1,global);
}

int main()
{
    Node *root = create_tree();
    cout<<"the left view of binary tree is : "<<endl;
    int global=0;
    printLeftView(root,0,global);
    return 0;
}