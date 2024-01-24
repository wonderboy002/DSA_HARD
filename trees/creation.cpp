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

void postorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
void preorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
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

Node *create_tree()
{
  int data;
  cout << "Enter data to insert in tree : " << endl;
  cin >> data;
  Node *root = new Node(data);
  if (data == -1)
  {
    return NULL;
  }

  cout << "left child of : " << root->data << endl;
  // creating left subtree of a given node
  root->left = create_tree();

  cout << "rigth child : " << root->data << endl;
  // creating the right subtree of a given node
  root->right = create_tree();

  return root;
}
int main()
{
  Node *root = create_tree();
  cout << "preorder traversal" << endl;
  preorder(root);

  cout<<"inorder traversal"<<endl;
  inorder(root);

  cout<<"postorder traversal "<<endl;
  postorder(root);

  return 0;
}