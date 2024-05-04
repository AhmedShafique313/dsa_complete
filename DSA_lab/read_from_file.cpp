#include <iostream>
#include <fstream>
using namespace std;

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

int main()
{
    int n, store[500];
    const char* file_open = "array_data.txt";
    readdata(file_open, store, n);
    printing(store, n);
    return 0;
}