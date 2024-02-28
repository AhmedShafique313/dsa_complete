#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    vector<vector<int>> data;

    // Constructor to initialize matrix with given dimensions
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c)) {}

    // Overloaded stream insertion operator for printing the matrix
    friend ostream& operator<<(ostream& os, const Matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            os << "[ ";
            for (int j = 0; j < mat.cols; j++) {
                os << mat.data[i][j] << " ";
            }
            os << "]" << endl;
        }
        return os;
    }
};

// Function to get matrix dimensions and values from the user
Matrix getMatrixInput(const string& matrixName) {
    int rows, cols;
    cout << "Enter the dimensions of " << matrixName << " (rows cols): ";
    cin >> rows >> cols;

    Matrix mat(rows, cols);
    cout << "Enter the elements of " << matrixName << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat.data[i][j];
        }
    }
    return mat;
}

// Function to perform matrix addition
Matrix addMatrices(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        throw invalid_argument("Matrices must have the same dimensions for addition.");
    }

    Matrix result(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

// Function to perform matrix subtraction
Matrix subtractMatrices(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        throw invalid_argument("Matrices must have the same dimensions for subtraction.");
    }

    Matrix result(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    return result;
}

int main() {
    string userName;
    cout << "Enter your name: ";
    getline(cin, userName); // Use getline to handle spaces in names

    Matrix mat1 = getMatrixInput("Matrix X");
    Matrix mat2 = getMatrixInput("Matrix Y");

    try {
        Matrix sum = addMatrices(mat1, mat2);
        cout << "Dear " << userName << ", the sum of X and Y is:\n" << sum << endl;

        Matrix difference = subtractMatrices(mat1, mat2);
        cout << "Dear " << userName << ", the difference of X and Y is:\n" << difference << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
