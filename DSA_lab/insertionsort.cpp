#include <iostream>
using namespace std;

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

void printing_sorted_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "[" << i << "]: " << arr[i] << endl;
    }
    return;
}

// Driver code
int main()
{
    int len = 7;
    int array[] = {8, 5, 9, 7, 3, 2, 6};
    // Call insertionSort to sort the array
    insertionSort(array, len);
    cout << "Insertion sort sorted this array" << endl;
    printing_sorted_array(array, len);
    return 0;
}
