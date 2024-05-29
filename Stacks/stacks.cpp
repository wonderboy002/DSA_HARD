#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int *arr, n, top;

public:
    Stack(int n)
    {
        arr = new int[n];
        this->n = n;
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
    bool isFull()
    {
        return top == n - 1 ? true : false;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack overflow!!! unable to push " << x << " onto the stack " << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!!!" << endl;
            return -1;
        }
        int temp = arr[top];
        top--;
        return temp;
    }
    int getTop()
    {
        return top == -1 ? -1 : arr[top];
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stack *st=new Stack(5);
    // cout<<st->isEmpty()<<endl;
    // cout<<st->isFull()<<endl;

    st->push(101);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    // st->push(6);
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    cout<<st->getTop()<<endl;
    st->display();
    return 0;
}