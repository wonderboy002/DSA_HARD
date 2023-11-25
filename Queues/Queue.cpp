#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size, front, rear;

    Queue(int size)
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
        return rear == size - 1 ? 1 : 0;
    }

    void push(int x)
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
        }
        else if (rear == size - 1)
        {
            cout << "Queue overflow" << endl;
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
        else if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
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
        cout << "Your Queue is : " << endl;
        if (!this->isEmpty())
        {

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
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
    Queue *q = new Queue(5);
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    cout << "queue is full ? : " << q->isFull() << endl;
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    cout << "Length of queue : " << q->getLength() << endl;

    q->push(69);
    q->push(39);
    q->push(49);
    q->push(59);

    cout << "Queue empty : " << q->isEmpty() << endl;

    q->display();
    cout << "front of queue : " << q->getFront() << endl;
    cout << "Rear of Queue : " << q->getRear() << endl;
    cout << "Length of queue : " << q->getLength() << endl;
    return 0;
}