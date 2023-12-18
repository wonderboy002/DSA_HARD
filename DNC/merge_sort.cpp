#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    int *left = new int[leftSize];
    int *right = new int[rightSize];

    int leftc, rightc;
    leftc = rightc = 0;
    for (int i = start; i <= mid; i++)
    {
        left[leftc++] = arr[i];
    }

    for (int i = mid + 1; i <= end; i++)
    {
        right[rightc++] = arr[i];
    }

    leftc = rightc = 0;
    int mainarrayIndex=start;

    while (leftc<leftSize && rightc<rightSize){
        if (left[leftc]<right[rightc]){
            arr[mainarrayIndex++]=left[leftc++];
        }
        else {
            arr[mainarrayIndex++]=right[rightc++];
        }
    }

    while (leftc<leftSize){
        arr[mainarrayIndex++]=left[leftc++];
    }

    while (rightc<rightSize){
        arr[mainarrayIndex++]=right[rightc++];
    }
}

void display(int *arr,int size){
    cout<<"array given by"<<endl;
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
int main()
{
    int arr[] = {2, 1, 9, 7, 4, 6,6,6,99};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr,n);
    mergeSort(arr, 0, n - 1);
    display(arr,n);
    return 0;
}