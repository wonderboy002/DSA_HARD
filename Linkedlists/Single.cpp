#include<bits/stdc++.h>
using namespace std;
class node {
    public :
       int data;
       node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtBeg(node *&head,node *&tail,int x){
    node *newnode=new node(x);
     if (head==NULL){
        //single element ka case
         head=tail=newnode;
         return;
     }

     newnode->next=head;
     //newnode ko purane head se link karo and head ko update karo
     head=newnode;
}

void insertAtEnd(node *&head,node *&tail,int x){
    node *newnode=new node(x);
    if (newnode==NULL){
        //single element ka case
        head=tail=newnode;
        return;
    }
    //purane tail ko newnode k saath link karo and tail ko update karo
    tail->next=newnode;
    tail=newnode;
}
void insertAtK(node *&head,node *&tail,int x,int k){
    node *newnode=new node(x);
    if (head==NULL){
        head=tail=newnode;
        return;
    }

    if (k==1){
        insertAtBeg(head,tail,x);
        return;
    }

    int count=1;
    node *p=head;
    while (count<k-1){
       p=p->next;
       count++;
    }
    //jaha pe insert karna hai uske ek node pehle aake khade ho jao
    //neccessary node links jamao 
    newnode->next=p->next;
    p->next=newnode;
}
void display(node *head){
    node *temp=head;
    cout<<"Your linked list is : "<<endl;
    while (temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
node *head=NULL;
node *tail=NULL;
insertAtBeg(head,tail,2);
insertAtBeg(head,tail,4);
insertAtBeg(head,tail,5);
insertAtBeg(head,tail,8);
insertAtBeg(head,tail,1);
insertAtEnd(head,tail,-11);
insertAtEnd(head,tail,-12);
insertAtEnd(head,tail,-13);
display(head);
insertAtK(head,tail,100,8);
display(head);
return 0;
}