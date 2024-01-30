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
        // in 0 based indexing left child 2*i+1,right child is 2*i+2,parent for i is (i-1)/2
        size = 0;
        this->capacity = capacity;
        arr = new int[capacity];
    }

    // insertion in heap
    void insert(int x)
    {
        if (size == capacity)
        {
            cout << "Heap overflow!!! unable to insert" << endl;
            return;
        }

        size++;
        arr[size - 1] = x;

        // heapify to maintain heap structure
        // checking conflict with parent node
        int index = size - 1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                // already at correct position
                break;
            }
        }
    }

    int popFromHeap(){
        int ans=arr[0];
        swap(arr[0],arr[size-1]);
        size--;

        int index=0;
        //0 based indexing mein size/2 se lekar size-1 tak saare leaf nodes hai toh unke liye delete karne k baad arrangements check karne ki need nhi hai
        while (index<=(size/2)-1){
            //
            int largest=index;
            int leftChild=2*index+1;
            int rightChild=2*index+2;

            if (leftChild<=size-1 && arr[leftChild]>arr[largest]){
                largest=leftChild;
            }

            if (rightChild<=size-1 && arr[rightChild]>arr[largest]){
                largest=rightChild;
            }

            if (index!=largest){
                swap(arr[index],arr[largest]);
                index=largest;
            }
            else {
                break;
                //correct position mein placed hai
            }
        }
        return ans;
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap *h = new Heap(10);
    h->insert(60);
    h->insert(50);
    h->insert(100);
    h->insert(30);
    h->insert(40);
    h->insert(42);
    h->insert(10);
    h->insert(32);
    h->insert(31);
    h->insert(20);
    cout<<"Before deletions : "<<endl;
    h->printHeap();
     
    cout<<"after deletions :"<<endl;
    h->popFromHeap();
    h->popFromHeap();
    h->popFromHeap();
    h->popFromHeap();
    h->printHeap();
    return 0;
}