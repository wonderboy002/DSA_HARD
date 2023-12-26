#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end)
{
    int i, j;
    j = start;
    i = start - 1;
    int pivot = end;
    //j index keep track of all elements less than pivot , while i keeps track of elements greater than pivot
    //once a smaller element is encountered
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    ++i;
    swap(arr[i], arr[pivot]);
    return i;
}

void display(int *arr, int size)
{
    cout << "array given by" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pi = partition(arr, s, e);
    quickSort(arr, s, pi - 1);
    quickSort(arr, pi + 1, e);
}
int main()
{
    int arr[] = {2, 1, 9, 7, 4, 4, 4, -1, 0, 2, 2, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    quickSort(arr, 0, n - 1);
    display(arr, n);
    return 0;
}