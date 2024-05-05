#include <iostream>
#include <algorithm>
using namespace std;

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

void printing_sorted_arrays(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << "[" << i << "]: " << arr[i] << endl;
    }
}

int main() {
    int len = 7;
    int array[len] = {8, 5, 9, 7, 3, 2, 6};
    heapsort(array, len);
    cout << "Heap sort sorted this array" << endl;
    printing_sorted_arrays(array, len);
    return 0;
}
