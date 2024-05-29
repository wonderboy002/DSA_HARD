#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert_beg(int x, node *&head, node *&tail)
{
    node *newnode = new node(x);
    if (head == NULL)
    {
        head = tail = newnode;
        return;
    }

    newnode->next = head;
    head = newnode;
}

void insert_tail(int x, node *&head, node *&tail)
{
    node *newnode = new node(x);
    if (head == nullptr)
    {
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

int length_LL(node *ptr)
{
    int cnt = 0;
    if (ptr == NULL)
    {
        return 0;
    }
    while (ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

void insert_k(int x, node *&head, node *&tail, int k)
{
    node *newnode = new node(x);
    if (k == 1)
    {
        insert_beg(x, head, tail);
        return;
    }

    if (k > length_LL(head) || k == 0)
    {
        cout << "Invalid position : " << endl;
        return;
    }

    int count = 1;
    node *p = head, *q = nullptr;
    while (p && count < k - 1)
    {
        count++;
        p = p->next;
    }

    newnode->next = p->next;
    p->next = newnode;
}

void display(node *ptr)
{
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int delete_first(node *&head, node *&tail)
{
    if (head == nullptr)
    {
        cout << "List empty!! deletion failed" << endl;
        return -1;
    }
    node *temp = head;
    int x = temp->data;
    head = head->next;
    if (!head)
    {
        head = tail = nullptr;
    }
    delete temp;
    return x;
}
int delete_last(node *&head, node *&tail)
{

    if (head == nullptr)
    {
        cout << "Deletion failed as list is already empty : " << endl;
        return -1;
    }
    if (head == tail)
    {
        return delete_first(head, tail);
    }
    node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    int x = tail->data;
    temp->next = tail->next;
    tail->next = NULL;
    node *temp2 = tail;
    tail = temp;
    delete temp2;
    return x;
}

int delete_k(node *&head, node *&tail, int k)
{
    if (k == 1)
    {
        return delete_first(head, tail);
    }
    else if (k == length_LL(head))
    {
        return delete_last(head, tail);
    }

    int cnt = 1;
    node *p, *q;
    p = head, q = nullptr;
    while (p && cnt != k)
    {
        q = p;
        p = p->next;
        cnt++;
    }
    q->next = p->next;
    p->next = nullptr;
    int x = p->data;
    delete p;
    return x;
}

int main()
{
    node *head = nullptr, *tail = nullptr;
    // insert_beg(1, head, tail);
    // insert_beg(3, head, tail);
    // insert_beg(5, head, tail);

    // insert_tail(11, head, tail);
    // insert_tail(33, head, tail);
    // insert_tail(55, head, tail);

    // int x = 0;
    // while (1)
    // {
    //     cout << "enter element to insert and its position : " << endl;
    //     int k;
    //     cin >> x >> k;
    //     if (k == -1)
    //         break;
    //     insert_k(x, head, tail, k);
    //     cout << "Linked list after insertion : " << endl;
    //     display(head);
    // }
    // display(head);

    // deletion of nodes in singly linked lists
    // display(head);
    // delete_last(head, tail);
    // delete_last(head, tail);
    // delete_last(head, tail);
    // display(head);

    // insert_tail(11, head, tail);
    // insert_tail(10, head, tail);
    // insert_tail(6, head, tail);
    // display(head);

    // delete_first(head, tail);
    // delete_first(head, tail);
    // delete_first(head, tail);
    // delete_first(head, tail);
    // delete_first(head, tail);
    // delete_first(head, tail);

    // insert_tail(11, head, tail);
    // insert_tail(10, head, tail);
    // insert_tail(6, head, tail);

    // delete_last(head,tail);
    // delete_last(head,tail);
    // delete_last(head,tail);

    // insert_tail(11, head, tail);
    // insert_tail(10, head, tail);
    // insert_tail(6, head, tail);

    insert_beg(1, head, tail);
    insert_beg(2, head, tail);
    insert_beg(3, head, tail);
    insert_beg(22, head, tail);
    insert_beg(32, head, tail);
    insert_beg(52, head, tail);
    insert_beg(12, head, tail);

    int k = 0;
    display(head);
    while (1)
    {
        cout << "Enter the position to delete " << endl;
        cin >> k;
        if (k == -1)
        {
            break;
        }
        delete_k(head, tail, k);
        cout << "List after deletion : " << endl;
        display(head);
    }
    display(head);
    return 0;
}