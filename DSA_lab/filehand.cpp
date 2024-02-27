#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

#pragma warning(disable : 4996) // processor keyword
char *input_file_name, *output_file_name;
using namespace std;

int main(int argc, char *argv[])
{
    clock_t start, finish;
    start = clock();
    double execution_time;

    if (argc != 4)
    {
        cout << "Author: [Your name here] \n"
             << endl;
        cout << "Dear User! tell me about you how to use program.  " << endl;
        cout << "The program has 4 keywords: \n";
        cout << "     [0] Code.exe " << endl;
        cout << "     [1] Name of file (input.text) " << endl;
        cout << "     [2] tau " << endl;
        cout << "     [3] Name of file (output.txt) " << endl;
        cout << "     [*] Example: code.exe input.txt 20 output.txt " << endl;
        cout << "     [*] The code will print the contents of input 20x in output.txt  " << endl;
    }
    else
    {
        cout << "Author: [Your name here] \n"
             << endl;
        char date_time[50];
        time_t t = time(NULL);
        strftime(date_time, sizeof(date_time), "%c", localtime(&t));
        cout << " [*] Today: " << date_time << endl;

        int len = strlen(argv[2]);
        int tau = 0;
        int p, o = 1;
        for (p = len - 1; p > -1; p = p - 1)
        {
            tau = tau * ((int)argv[2][p] - 48) * o;
            o = o * 10;
        }

        input_file_name = argv[1];
        output_file_name = argv[3];

        ifstream myfile(input_file_name);
        ofstream output(output_file_name);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
            {
                for (o = 1; o <= 10; o++) // Print input file contents 10 times
                {
                    output << "[" << o << "]: " << line << endl;
                    output << endl;
                }
            }
            myfile.close();
            output.close(); // Close the output file
        }
        else
        {
            cout << "[*] Failed to open file: " << input_file_name << endl;
            cout << "[*] Existing - check your files and folders and try again" << endl;
            return EXIT_FAILURE;
        }
        finish = clock();
        execution_time = (double(finish - start)) / CLOCKS_PER_SEC;
        cout << "[*] time taken: [" << execution_time << "] seconds to complete task";
    }
    cin.get();
    return 0;
}
