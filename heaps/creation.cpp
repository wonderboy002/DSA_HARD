#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    int size;
    int capacity;
    int *arr;
    Heap(int capacity)
    {
        size = 0;
        this->capacity = capacity;
        this->arr = new int[capacity];
    }

    void insert(int x)
    {
        // check whether has reached its max capacity
        if (size == capacity)
        {
            cout << "Heap overflow!!! unable to insert " << x << endl;
            return;
        }

        size++;
        arr[size] = x;

        // Heapify to place at the current position
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            // move to correct position
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            // already at correct position
            else
            {
                break;
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int deleteFromHeap()
    {
        // store the ans and swap with the last node
        int ans = arr[1];
        swap(arr[1], arr[size]);
        size--;

        int index = 1;
        while (index <= size)
        {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            int largestIndex = index;
            //check whether left and right children are greater than the index node
            if (leftChild <= size && arr[leftChild] > arr[largestIndex])
            {
                largestIndex = leftChild;
            }

            if (rightChild <= size && arr[rightChild] > arr[largestIndex])
            {
                largestIndex = rightChild;
            }
            //already at the correct node
            if (index == largestIndex)
            {
                break;
            }
            //swap the index node with the largest node
            else
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return ans;
    }
};
int main()
{
    Heap *h = new Heap(20);
    // h->insert(10);
    // h->insert(20);
    // h->insert(5);
    // h->insert(11);
    // h->insert(6);
    // h->display();

    h->insert(5);
    h->insert(10);
    h->insert(15);
    h->insert(6);
    h->insert(25);
    h->insert(50);
    h->display();

    h->deleteFromHeap();
    cout<<"deletion successfull"<<endl;
    h->display();
    return 0;
}