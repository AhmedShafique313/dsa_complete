#include <iostream>
#include <string>
#include <new>
#include <fstream>
#include <time.h>
#include <string.h>
#include <ctime>
using namespace std;

struct element
{
    int r,c, *p;
};

void initialize_matrix(int row, int col, int *ptr, ifstream* file_in)
{
    int k;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*file_in) >> k;
            *(ptr + i*col + j) = k;
        }
    }
    return;
}

element addition_matrces(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if ((r1==r2) && (c1==c2))
        {
           cout<<"Processing addition of matrices"<<endl;
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int [r1*c1];
            int a,b,c;
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    a= *(p1 + i*c1 + j);
                    b = *(p2 + i*c1 + j);
                    c = a + b;
                    *(matrix.p + i*c1 + j) = c;
                }
            }
        }
        else throw(c1);
    }
    catch(...)
    {
        cout<<"Addition is not possible at this time"<<endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

element substraction_matrces(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if ((r1==r2) && (c1==c2))
        {
            cout<<"Processing subtraction of matrices"<<endl;
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int [r1*c1];
            int a,b,c;
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    a= *(p1 + i*c1 + j);
                    b = *(p2 + i*c1 + j);
                    c = a - b;
                    *(matrix.p + i*c1 + j) = c;
                }
            }
        }
        else throw(c1);
    }
    catch(...)
    {
        cout<<"substraction is not possible at this time"<<endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

void printing_matrix(int row, int col, int *ptr) {
    for (int i = 0; i < row; i++) {
        cout << "[";
        for (int j = 0; j < col; j++) {
            cout << " " << *ptr;
            ptr = ptr + 1;
        }
        cout << " ]" << endl;
    }
}

int main(int argc, char *argv [])
{
  int r1, c1;
  int r2, c2;
  ifstream myfile;

  int *p1, *p2;
  p1 = new int [r1*c1];
  p2 = new int [r2*c2];

  string input;
  try
  {
    if (argc!=1)
    {
        throw(argc);
    }
    else
    {
        myfile.open ("xy.txt");
        if (!myfile.is_open()) 
        {
            throw runtime_error("Failed to open file 'xy.txt'."); // handle file errors
        }
        cout<<"The dimensions of matrix X are: ";
        myfile >> r1;cout<<" ";myfile>>c1;
        cout<<r1<<" "<<c1;
        cout<<endl;
        cout<<"The dimensions of matrix Y are: ";
        myfile >> r2;cout<<" ";myfile>>c2;
        cout<<r2<<" "<<c2;
        cout<<endl;
        initialize_matrix(r1,c1,p1,&myfile);
        printing_matrix(r1,c1,p1);
        initialize_matrix(r2,c2,p2,&myfile);
        printing_matrix(r2,c2,p2);
        element matrix1, matrix2;
        matrix1 = addition_matrces(r1,c1,r2,c2,p1,p2);
        printing_matrix(matrix1.r, matrix1.c, matrix1.p);
        matrix2 = substraction_matrces(r1,c1,r2,c2,p1,p2);
        printing_matrix(matrix2.r, matrix2.c, matrix2.p);
    }
    
    
  }
  catch(...)
  {
    cout<<"Its not working"<<endl;
  }
  cin.get();
  delete [] p1;
  delete [] p2;
  myfile.close(); 
  return 0;
}