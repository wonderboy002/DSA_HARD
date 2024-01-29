#include <bits/stdc++.h>
using namespace std;
void display(int *arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int *arr,int n,int index){
    int left=2*index;
    int right=2*index+1;
    int largest=index;
    
    //find out the largest element among root,left,right
    if (left<=n && arr[left]>arr[largest]){
        largest=left;
    }

    if (right<=n && arr[right]>arr[largest]){
        largest=right;
    }

    if (largest!=index){
        //swap with the root
        swap(arr[index],arr[largest]);
        index=largest;
        heapify(arr,n,index);
        //continue downwards and heapify the subtrees
    }
}

void buildHeap(int *arr,int size){
    for (int i=size/2;i>=1;i--){
        heapify(arr,size,i);
    }
}

void heapSort(int *arr,int size){
    while (size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);

    }
}

int main()
{
    int *arr, n;
    cout << "enter the size of array : " << endl;
    cin >> n;

    arr = new int[n + 1];
    arr[0] = -1;
    cout << "enter array elements : " << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array is given by : " << endl;
    display(arr, n);

    buildHeap(arr, n);
    cout<<"corresponding heap's given by : "<<endl;
    display(arr,n);

    heapSort(arr,n);
    cout<<"sorted array's given by : "<<endl;
    display(arr,n);
    return 0;
}