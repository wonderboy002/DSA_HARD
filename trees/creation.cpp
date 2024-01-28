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
  if (!root)
  {
    return;
  }

  // node whose left and right subtrees are visited is processed
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
void preorder(Node *root)
{
  if (!root)
  {
    return;
  }
  // node is processed first then left and right subtrees are visited
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if (!root)
  {
    return;
  }
  // left subtree is visited first then node is processed
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

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

  //node for which left and right subtrees are visited is returned
  cout << "Enter data for left child of " << root->data << endl;
  root->left = create_tree();

  cout << "Enter data for right child of " << root->data << endl;
  root->right = create_tree();

  return root;
}
int main()
{
  Node *root = create_tree();
  cout << endl;
  cout << "preorder traversal" << endl;
  preorder(root);

  cout << "inorder traversal" << endl;
  inorder(root);

  cout << "postorder traversal " << endl;
  postorder(root);

  return 0;
}