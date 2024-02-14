#include<iostream>
#include<fstream>
using namespace std;
// unction that reads the entries from file.
// so we use some char array, int array and refernce in this function.
void readfromfile(char file_covert[], int elements[], int &entries)
{
    // convert the text file to char array
    ifstream conversion(file_covert);
    // linked the file entries to reference
    conversion>>entries;
    for (int i = 0; i < entries; i++)
    {
        /* code */
        // convert the file to integer array
        conversion>>elements[i];
    }
    return;
}


// printing the result
void printing(int sample[],int n)
{
    cout<<"Printing text file data: ";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<sample[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    // count the entries and store them in integer array
    int count, storing[100];
    //linked text file to character arrray
    char filename[12]={"s.txt"};
    readfromfile(filename,storing,count);
    // showing(count,storing);
    printing(storing,count);
    system("pause");
    return 0;
}