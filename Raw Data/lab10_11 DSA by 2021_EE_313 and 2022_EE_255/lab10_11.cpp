#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <time.h>
#include "gnuplot-iostream.h"
using namespace std;
using namespace std::chrono;

void fun(){

    cout<<"Fun() start \n";
    
    while (1)
    {
        if (getchar())
        {
        }    
    }    
    
   cout<<"Fun() ends \n";
}

void readdata(const char* file_convert, int element[], int &entries) 
{
    ifstream convert(file_convert);
    convert >> entries;
    for (int i = 0; i < entries; i++)
    {
        convert >> element[i];
    }
}

void printing(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<"["<<i<<"]: "<<arr[i]<<endl;
    }
    return;
}

void heapify(int arr[], int length, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, length, largest);
    }
}

void heapsort(int arr[], int length) {
    // Build heap (rearrange array)
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, length, i);
    }

    // One by one extract an element from heap
    for (int i = length - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void CountSort(int arr[], int length) {
    // Find the maximum element in the array
    int maxNum = arr[0];
    for (int i = 1; i < length; ++i) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }

    // Create a count array to store count of individual numbers
    int count[maxNum + 1] = {0};

    // Count the occurrences of each number in the input array
    for (int i = 0; i < length; ++i) {
        ++count[arr[i]];
    }

    // Modify count array to store actual position of each number in the output array
    for (int i = 1; i <= maxNum; ++i) {
        count[i] += count[i - 1];
    }

    // Create an output array
    int output[length];

    // Build the output array
    for (int i = length - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < length; ++i) {
        arr[i] = output[i];
    }
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int length, int exp)
{
    // output array
    int output[length];
    int i, count[10] = { 0 };
  
    // Store count of occurrences in count[]
    for (i = 0; i < length; i++)
        count[(arr[i] / exp) % 10]++;
  
    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    // Build the output array
    for (i = length - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
  
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < length; i++)
        arr[i] = output[i];
}
  
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int length)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, length);
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, length, exp);
}

int bubbleSort(int arr[], int length)
{
    int temp;
    for (int j = 0; j < length; j++)
    {
        int swap = 0;
        for (int i = 0; i < length-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i]= arr[i+1];
                arr[i+1]= temp;
                swap = swap + 1;
            }   
        }   
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void InsertionSort(float arr[], int length) {
    for (int i = 1; i < length; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketsort(float arr[], int length) {
    const int bucketSize = 10; // Define the number of buckets
    float maxVal = *max_element(arr, arr + length); // Find the maximum value in the array
    float minVal = *min_element(arr, arr + length); // Find the minimum value in the array

    // Create an array of buckets
    float buckets[bucketSize][length];

    // Initialize buckets
    for (int i = 0; i < bucketSize; i++) {
        fill_n(buckets[i], length, -1); // Initialize each bucket with -1
    }

    // Scatter the array elements into buckets
    for (int i = 0; i < length; i++) {
        int index = (int)((arr[i] - minVal) / (maxVal - minVal) * (bucketSize - 1));
        int j = 0;
        while (buckets[index][j] != -1) {
            j++;
        }
        buckets[index][j] = arr[i];
    }

    // Sort individual buckets and merge them back into the original array
    int index = 0;
    for (int i = 0; i < bucketSize; i++) {
        InsertionSort(buckets[i], length);
        for (int j = 0; j < length; j++) {
            if (buckets[i][j] != -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

void insertionSort(int arr[], int length)
{
    int i, j, key;
    for (i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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

void selectionSort(int arr[], int lenght)
{
    int min_idx;
    
    for (int i = 0; i < lenght - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (int j = i + 1; j < lenght; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void printing_sorted_arrays(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "[" << i << "]: " << arr[i];
    }cout<<endl;
}

void fprinting_sorted_arrays(float arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "[" << i << "]: " << arr[i];
    }cout<<endl;
}

int main()
{
   

    int n, store[500];
    const char* file_open = "array_data.txt";
    readdata(file_open, store, n);
    printing(store, n);


    cout<<"HeapSort Applying................."<<endl;
    // Measure run-time for HeapSort
    auto start = high_resolution_clock::now();
    
    heapsort(store, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "HeapSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);


    cout<<"CountSort Applying................."<<endl;
    start = high_resolution_clock::now();
    CountSort(store, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "CountSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);


    cout<<"RadixSort Applying................."<<endl;
    start = high_resolution_clock::now();
    radixsort(store, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "RadixSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);


    cout<<"BubbleSort Applying................."<<endl;
    start = high_resolution_clock::now();
    bubbleSort(store, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "BubbleSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);


    cout<<"QuickSort Applying................."<<endl;
    start = high_resolution_clock::now();
    quickSort(store, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "QuickSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);


    cout<<"BucketSort Applying................."<<endl;
    start = high_resolution_clock::now();
    int len = 9;
    float array[len] = {8.48, 5.27, 9.10, 7.89, 3.01, 2.48, 6.32, 1.95, 1.27};
    bucketsort(array, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "BucketSort Time: " << duration.count() << " milliseconds" << endl;
    fprinting_sorted_arrays(array,len);


    cout<<"InsertionSort Applying................."<<endl;
    start = high_resolution_clock::now();
    insertionSort(store, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "InsertionSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);

    
    cout<<"MergeSort Applying................."<<endl;
    start = high_resolution_clock::now();
    merge_sort(store,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "MergeSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);


    cout<<"SelectionSort Applying................."<<endl;
    start = high_resolution_clock::now();
    selectionSort(store, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "SelectionSort Time: " << duration.count() << " milliseconds" << endl;
    printing_sorted_arrays(store,n);
    return 0;
}