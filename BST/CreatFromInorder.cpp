#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
       int data;
       Node *left;
       Node *right;
       
       Node (int data){
        left=right=NULL;
        this->data=data;
       }
};

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

Node *createBST(int *arr,int s,int e){
    //base cases
    if (s>e){
        return NULL;
    }

    int mid=s+(e-s)/2;
    Node *root=new Node(arr[mid]);

    //recursive calls kar do left aur right subtrees banane k liye
    root->left=createBST(arr,s,mid-1);
    root->right=createBST(arr,mid+1,e);
    return root;

}

int main(){
int arr[]={90,96,101,103,401,506,1000};
Node *root=createBST(arr,0,6);
cout<<"level order traversal of created BST is : "<<endl;
level_order_traversal(root);
return 0;
}