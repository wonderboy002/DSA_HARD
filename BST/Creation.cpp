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

int minimum(Node *root){
    while (root->left){
        root=root->left;
    }
    return root->data;
}

int maximum(Node *root){
    while (root->right){
        root=root->right;
    }
    return root->data;
}

bool SearchInBST(Node *root,int key){
    //base cases
    if (root==NULL){
        return false;
    }

    if (root->data==key){
        return true;
    }
    
    // search in left or right subtrees
    return SearchInBST(root->left,key) || SearchInBST(root->right,key);
}

Node *DeleteFromBST(Node *root,int x){
    if (root==NULL){
        return NULL;
    }

    if (root->data==x){
       //4 cases for node deletion

       //case 1 leaf node
       if (!root->left && !root->right){
        return NULL;
       }

       //case 2 left null and right not null
       else if (!root->left && root->right){
        Node *child=root->right;
        delete root;
        return child;
       }

       //case 3 left not null and right null
       else if (!root->right && root->left){
        Node *child=root->left;
        delete root;
        return child;
       }
       
       //case 4 a proper node 
       else {
          int LST=maximum(root->left);
          root->data=LST;
          root->left=DeleteFromBST(root->left,LST);
       }
    }

    else if (root->data>x){
        root->left=DeleteFromBST(root->left,x);
    }
    else {
        root->right=DeleteFromBST(root->right,x);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    createTree(root);
    cout << "BST successfully created" << endl;
    inorder(root);
    cout<<endl;

    //  50 30 60 20 40 25 55 70 80 -1

    cout<<"Minimum of BST : "<<minimum(root)<<endl;
    cout<<"Maximum of BST : "<<maximum(root)<<endl;

    int key;
    cout<<"Enter key to search in BST : "<<endl;
    cin>>key;

    bool ans=SearchInBST(root,key);
    ans==true?cout<<"Value exists in BST":cout<<"Value does not exist in BST"<<endl;

    int x;
    cout<<"enter a key to delete from BST"<<endl;
    cin>>x;

    root=DeleteFromBST(root,x);
    cout<<"BST after deletion : "<<endl;
    inorder(root);
    return 0;
}