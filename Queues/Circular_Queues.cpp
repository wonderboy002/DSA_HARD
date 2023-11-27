#include <iostream>
using namespace std;
class Circular_Queue
{
public:
    int *arr;
    int size, front, rear;

    Circular_Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1 ? 1 : 0;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == (rear + 1) % size) ? 1 : 0;
    }

    void push(int x)
    {
        if (this->isEmpty())
        {
            front++;
            rear++;
            arr[rear] = x;
        }
        else if (this->isFull())
        {
            cout << "Circular_Queue overflow" << endl;
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

    int pop()
    {
        int temp = -1;
        if (front == rear)
        {
            temp = arr[front];
            front = rear = -1;
        }
        else if (this->isEmpty())
        {
            cout << "Circular_Queue underflow" << endl;
        }
        else if (front == size - 1)
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

    int getFront()
    {
        return !this->isEmpty() ? arr[front] : -1;
    }

    int getRear()
    {
        return !this->isEmpty() ? arr[rear] : -1;
    }

    int getLength()
    {
        return !this->isEmpty() ? (rear - front + 1) : 0;
    }

    void display()
    {
        cout << "Your Circular_Queue is : " << endl;
        if (!this->isEmpty())
        {
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = i == size - 1 ? 0 : i + 1;
            }
            cout << arr[rear] << " ";
        }
        else
        {
            cout << "QUEUE IS EMPTY!!!" << endl;
        }
        cout << endl;
    }
};
int main()
{
    Circular_Queue *q = new Circular_Queue(5);
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    q->pop();
    q->pop();
    q->pop();
    q->push(60);
    q->push(610);
    q->push(650);

    cout << "Queue full?" << q->isFull() << endl;
    cout << "Queue Empty?" << q->isEmpty() << endl;

    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    cout << "Queue Empty?" << q->isEmpty() << endl;
    cout << "Queue Full?" << q->isFull() << endl;

    q->push(10);
    q->push(20);
    q->push(30);

    q->display();
    return 0;
}