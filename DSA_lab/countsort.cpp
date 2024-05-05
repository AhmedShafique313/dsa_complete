#include <iostream>
using namespace std;

void countSort(int arr[], int length) {
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

void printing_sorted_arrays(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<"["<<i<<"]: "<<arr[i]<<endl;
    }
    return;
}

int main ()
{
    int len = 7;
    int array [len] = {8,5,9,7,3,2,6};
    countSort(array, len);
    cout<<"Bubble sort sorted this array"<<endl;
    printing_sorted_arrays(array,len);
    return 0;
}