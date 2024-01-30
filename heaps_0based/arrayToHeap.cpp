#include <bits/stdc++.h>
using namespace std;
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int *arr,int n){
    while (n>1){
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
    }
}

int main()
{
    int *arr, n;
    cout << "enter array size : " << endl;
    cin >> n;
    cout << "enter array elements : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildHeap(arr, n);
    cout << "Equivalent heap : " << endl;
    display(arr, n);

    heapSort(arr,n);
    cout<<"array after applying heap sort : "<<endl;
    display(arr,n);
    return 0;
}