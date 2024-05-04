#include <iostream>
using namespace std;

int bubble_Sort(int arr[], int length)
{
    int temp;
    for (int j = 0; j < length; j++)
    {
        for (int i = 0; i < length-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i]= arr[i+1];
                arr[i+1]= temp;

            }   
        }   
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
    printing_sorted_arrays(array,len);
    bubble_Sort(array, len);
    cout<<"Bubble sort sorted this array"<<endl;
    printing_sorted_arrays(array,len);
    return 0;
}