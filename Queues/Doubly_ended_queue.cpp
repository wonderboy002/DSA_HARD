#include <bits/stdc++.h>
using namespace std;
class doubly_ended_queue
{
public:
    int *arr;
    int front, rear, size;

    doubly_ended_queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1) ? 1 : 0;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front == (rear + 1) % size)) ? 1 : 0;
    }

    void push_front(int x)
    {
        if (isFull())
        {
            cout << "push front failed due to overflow!!!" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear++;
            front++;
            arr[front] = x;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = x;
        }
        else
        {
            front--;
            arr[front] = x;
        }
    }

    void push_back(int x)
    {
        if (isFull())
        {
            cout << "queue overflow unable to push" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear++;
            front++;
            arr[rear] = x;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }

    int pop_front()
    {
        int temp = -1;
        if (isEmpty())
        {
            cout << "pop front failed due to underflow!!!" << endl;
        }
        else if (front == rear)
        {
            temp = arr[front];
            front = rear = -1;
        }
        else if (front == size - 1 && rear != 0)
        {
            temp = arr[front];
            front = 0;
        }
        else
        {
            temp = arr[front];
            front++;
        }
        return temp;
    }

    int pop_back()
    {
        int temp = -1;
        if (isEmpty())
        {
            cout << "pop back failed due to underflow!!!" << endl;
        }
        else if (front == rear)
        {
            temp = arr[rear];
            front = rear = -1;
        }
        else if (rear == 0 && front != size - 1)
        {
            temp = arr[rear];
            rear = size - 1;
        }
        else
        {
            temp = arr[rear];
            rear--;
        }
        return temp;
    }

    int getFront()
    {
        return !isEmpty() ? arr[front] : -1;
    }

    int getRear()
    {
        return !isEmpty() ? arr[rear] : -1;
    }

    void display()
    {
        if (!isEmpty())
        {
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = (i == size - 1) ? 0 : i + 1;
            }
            cout << arr[rear] << " ";
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
        cout << endl;
    }
};

int main()
{
    doubly_ended_queue *dq = new doubly_ended_queue(5);
    dq->push_back(10);
    dq->push_back(20);
    dq->push_back(30);
    dq->push_back(40);
    dq->push_back(50);
    dq->pop_front();
    dq->pop_front();
    dq->pop_front();
    cout << "is our queue full???" << dq->isFull() << endl;
    dq->push_front(100);
    dq->push_front(200);
    dq->push_front(300);
    cout << "is our queue full???" << dq->isFull() << endl;
    dq->display();
    dq->pop_back();
    dq->pop_back();
    dq->pop_back();
    dq->pop_back();
    dq->pop_back();
    dq->display();
    cout << "is our queue full??" << dq->isFull() << endl;
    cout << "is our queue empty??" << dq->isEmpty() << endl;

    dq->push_back(100);
    dq->push_front(200);
    dq->push_front(300);
    dq->push_back(3100);
    dq->display();

    cout << "front element :: " << dq->getFront() << endl;
    cout << "rear element :: " << dq->getRear() << endl;
    return 0;
}