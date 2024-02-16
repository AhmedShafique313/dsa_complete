#include <iostream>
#include <string>
#include <algorithm> // Added for sorting
#include <cmath>

using namespace std;

struct student {
    string name;
    double chem;
    double phy;
    double math;
};

int length = 0;

void initial(int n, struct student **data_arr) {
    cout << "----------- Loading ----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]: " << "Enter the name of Student: ";
        cin >> data_arr[i]->name;
        cout << endl;
        cout << "Enter the chemistry marks: ";
        cin >> data_arr[i]->chem;
        cout << "Enter the physics marks: ";
        cin >> data_arr[i]->phy;
        cout << "Enter the math marks: ";
        cin >> data_arr[i]->math;
        cout << endl;
    }
    cout << "---------- Please Wait ----------" << endl;
    length = length + 1;
    cout << endl;
    return;
}

bool compareByName(const student* a, const student* b) {
    return a->name < b->name;
}

void sort(int n, struct student **data_arr) {
    cout << "---------- Alphabetized order ----------" << endl;
    sort(data_arr, data_arr + n, compareByName);
    return;
}

void printing(int n, struct student **data_arr) {
    cout << "---------- Loading -----------" << endl;
    cout << endl << "---------- Recorded Data -----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]: " << "Name: " << data_arr[i]->name
            << " Chemistry: " << data_arr[i]->chem
            << " Physics: " << data_arr[i]->phy
            << " Math: " << data_arr[i]->math << endl;
    }
    cout << endl;
    length = length + 1;
}

int main() {
    int n;
    cout << "Enter the number of student's data that you want to store in structure: ";
    cin >> n;
    cout << endl;
    student* arr[n]; // array of structure
    student* ptr_arr[n]; // pointer array points to structure.
    for (int i = 0; i < n; i++) {
        ptr_arr[i] = new student; // new pointer structure & new multiples dynamic memory allocations.
    }
    cout << endl;
    initial(n, ptr_arr); // calling with original ptr_arr[] instead of data_arr[].
    sort(n, ptr_arr);
    printing(n, ptr_arr);
    cout << "Length of Function: " << length << endl;
    for (int i = 0; i < n; i++) {
        delete ptr_arr[i];
    }
    return 0;
}