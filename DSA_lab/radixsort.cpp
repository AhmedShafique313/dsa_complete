#include<iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
  
// A function to do counting sort of arr[] according to
// the digit represented by exp.
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
  
// A utility function to print an array
void printing_sorted_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "[" << i << "]: " << arr[i] << endl;
    }
}
  
// Driver program to test above functions
int main()
{
    int len = 7;
    int array[len] = { 170, 450, 755, 802, 245, 265, 660 };
      // Radix sort function
    radixsort(array, len);
    printing_sorted_array(array, len);
    return 0;
}