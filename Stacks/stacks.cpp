#include <bits/stdc++.h>
using namespace std;
class Stacks
{
public:
    int *arr;
    int n;
    int top;

    Stacks(int n)
    {
        this->arr = new int[n];
        this->top = -1;
        this->n = n;
    }

    void push(int x)
    {
        // stack overflow case
        if (top == n - 1)
        {
            cout << "stack overflow!!!"
                 << " unable to push " << x << " onto the stack : " << endl;
            return;
        }
        this->top++;
        arr[top] = x;
    }

    int pop()
    {
        // stack underflow case
        if (top == -1)
        {
            cout << "stack underflow unable to pop : " << endl;
            return 9999;
        }
        int temp = arr[top];
        this->top--;
        return temp;
    }

    bool isEmpty()
    {
        return this->top == -1 ? true : false;
    }

    bool isFull()
    {
        return this->top == n - 1;
    }

    int getTop()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        return 9999;
    }

    void display()
    {
        //stl jaise print karne gye toh orignal stack hi empty ho jayegi hue hue hue
        cout << "Your stack is given by : " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stacks *s = new Stacks(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(41);

    s->display();
    cout << "Stack top given by : " << s->getTop() << endl;

    s->pop();
    s->pop();
    s->pop();

    s->display();

    cout << "Stack full : " << s->isFull() << endl;
    cout << "Stack empty : " << s->isEmpty() << endl;
    cout << "Stack top given by : " << s->getTop() << endl;
    return 0;
}