#include<iostream>
#include<new> 

using namespace std;

// Function for Selection sort
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

// Function to print an array
void printing_sorted_arrays(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<"["<<i<<"]: "<<arr[i]<<endl;
    }
    return;
}
// Driver program
int main()
{
    int len = 7;
    int array[] = {8,5,9,7,3,2,6};
    // Function Call
    selectionSort(array, len);
    cout<<"Selection sort sorted this array"<<endl;
    printing_sorted_arrays(array,len);
    return 0;
}