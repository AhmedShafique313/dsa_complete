#include <iostream>
using namespace std;

void mergesort(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* left_half = new int[n1];
    int* right_half = new int[n2];

    // Copy data to temp arrays left_half[] and right_half[]
    for (int i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (left_half[i] <= right_half[j])
        {
            arr[k] = left_half[i];
            i++;
        }
        else
        {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_half[], if any
    while (i < n1)
    {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_half[], if any
    while (j < n2)
    {
        arr[k] = right_half[j];
        j++;
        k++;
    }

    delete[] left_half;
    delete[] right_half;
}

// for recursively call merge sort because its recursive sort
// cutting array recursively
void merge_sort(int arr[], int left, int right)
{
    if (left<right)
    {
        int mid = left+(right-left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        mergesort(arr,left,mid,right);
    }
    
}

void printing_sorted_arrays(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<"["<<i<<"]: "<<arr[i]<<endl;
    }
    return;
}

int main()
{
    int len = 7;
    int array [len] = {8,5,9,7,3,2,6};
    int l,r,m;
    merge_sort(array,0,len-1);
    cout<<"Merge sort sorted this array"<<endl;
    printing_sorted_arrays(array,len);
    return 0;
}