#include <iostream>
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
        this->n = n;
        this->top = -1;
    }

    void push(int x)
    {
        if (this->top == n - 1)
        {
            cout << "Stack Overflow!!! unable to push " << x << " to the stack " << endl;
        }
        else
        {
            this->top++;
            this->arr[this->top] = x;
        }
    }

    int pop()
    {
        if (this->top == -1)
        {
            cout << "Stack underflow!!! unable to pop" << endl;
        }
        else
        {
            int x = arr[top];
            top--;
            return x;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == n - 1)
        {
            return true;
        }
        return false;
    }

    int getTop()
    {
        if (top != -1)
        {
            return arr[top];
        }
    }

    void print()
    {
        cout << "Stack is given by" << endl;
        if (top != 1)
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
        else {
            cout<<"Stack is empty"<<endl;
        }
    }
};
int main()
{
    Stacks *s = new Stacks(6);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(5);
    s->push(6);
    s->push(8);
    s->push(81);

    
    s->print();

    s->pop();
    s->pop();

    s->print();
    return 0;
}