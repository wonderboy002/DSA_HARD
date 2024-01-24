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

void level_order_traversal(Node *root)
{
    queue<Node *> Q;
    // push the root node
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        // acquire the node to be processed and remove it from the queue
        Node *temp = Q.front();
        Q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (Q.empty()){
                break;
            }
            Q.push(NULL);
        }
        // push the left and right child of the acuired node if they exist
        else
        {
            if (temp->left)
            {
                Q.push(temp->left);
            }

            if (temp->right)
            {
                Q.push(temp->right);
            }
            cout << temp->data << " ";
        }
    }
}

int main()
{
    Node *root = create_tree();
    cout << "the level order traversal of given tree is : " << endl;
    level_order_traversal(root);
    return 0;
}