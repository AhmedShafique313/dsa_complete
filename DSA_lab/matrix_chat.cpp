#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <ctime>

using namespace std;

struct element
{
    int r, c, *p;
};

void initialize_matrix(int row, int col, int *ptr)
{
    int k;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> k;
            *(ptr + i * col + j) = k;
        }
    }
    return;
}

element addition_matrices(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if ((r1 == r2) && (c1 == c2))
        {
            cout << "Processing addition of matrices" << endl;
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int[r1 * c1];
            int a, b, c;
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    a = *(p1 + i * c1 + j);
                    b = *(p2 + i * c1 + j);
                    c = a + b;
                    *(matrix.p + i * c1 + j) = c;
                }
            }
        }
        else
            throw(c1);
    }
    catch (...)
    {
        cout << "Addition is not possible at this time" << endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

element subtraction_matrices(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if ((r1 == r2) && (c1 == c2))
        {
            cout << "Processing subtraction of matrices" << endl;
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int[r1 * c1];
            int a, b, c;
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    a = *(p1 + i * c1 + j);
                    b = *(p2 + i * c1 + j);
                    c = a - b;
                    *(matrix.p + i * c1 + j) = c;
                }
            }
        }
        else
            throw(c1);
    }
    catch (...)
    {
        cout << "Subtraction is not possible at this time" << endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

void printing_matrix(int row, int col, int *ptr, string name)
{
    cout << "Dear " << name << "! "
         << "Matrix X has following contents: " << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < col; j++)
        {
            cout << " " << *ptr; // Corrected dereferencing here
            ptr = ptr + 1;
        }
        cout << " ]" << endl;
    }
    return;
}

void add_printing_matrix(int row, int col, int *ptr, string name)
{
    cout << "Dear " << name << "! "
         << "Z = X + Y is shown below:" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < col; j++)
        {
            cout << " " << *ptr; // Corrected dereferencing here
            ptr = ptr + 1;
        }
        cout << " ]" << endl;
    }
    return;
}

void sub_printing_matrix(int row, int col, int *ptr, string name)
{
    cout << "Dear " << name << "! "
         << "Z = X - Y is shown below:" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < col; j++)
        {
            cout << " " << *ptr; // Corrected dereferencing here
            ptr = ptr + 1;
        }
        cout << " ]" << endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Usage: " << argv[0] << " <input_file_name> <tau> <output_file_name>" << endl;
        return 1;
    }

    char *input_file_name = argv[1];
    int tau = atoi(argv[2]);
    char *output_file_name = argv[3];

    ifstream myfile(input_file_name);
    ofstream output(output_file_name);

    if (!myfile.is_open())
    {
        cout << "Failed to open file: " << input_file_name << endl;
        return 1;
    }

    string user;
    cout << "Enter name of current user?: ";
    cin >> user;
    cout << endl;
    cout << "Dear " << user << "! "
         << "Tell me what are the dimensions of X?: " << endl;
    int r1, c1;
    cin >> r1 >> c1;
    int *p1 = new int[r1 * c1];
    cout << "Dear " << user << "! "
         << "Enter the contents of X:" << endl;
    initialize_matrix(r1, c1, p1);
    printing_matrix(r1, c1, p1, user);

    cout << "Dear " << user << "! "
         << "Tell me what are the dimensions of Y?: " << endl;
    int r2, c2;
    cin >> r2 >> c2;
    int *p2 = new int[r2 * c2];
    cout << "Dear " << user << "! "
         << "Enter the contents of Y:" << endl;
    initialize_matrix(r2, c2, p2);
    printing_matrix(r2, c2, p2, user);

    element matrix1, matrix2;
    matrix1 = addition_matrices(r1, c1, r2, c2, p1, p2);
    add_printing_matrix(matrix1.r, matrix1.c, matrix1.p, user);

    matrix2 = subtraction_matrices(r1, c1, r2, c2, p1, p2);
    sub_printing
