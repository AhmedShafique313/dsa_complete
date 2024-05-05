#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(float arr[], int length) {
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
        insertionSort(buckets[i], length);
        for (int j = 0; j < length; j++) {
            if (buckets[i][j] != -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

void printing_sorted_array(float arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "[" << i << "]: " << arr[i] << endl;
    }
}

int main() {
    int len = 9;
    float array[len] = {8.48, 5.27, 9.10, 7.89, 3.01, 2.48, 6.32, 1.95, 1.27};
    bucketsort(array, len);
    cout << "Bucket sort sorted this array" << endl;
    printing_sorted_array(array, len);
    return 0;
}
