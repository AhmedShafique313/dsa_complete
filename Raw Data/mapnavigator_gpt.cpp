#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int MAX_ROWS = 10; // Maximum number of rows in the map
const int MAX_COLS = 10; // Maximum number of columns in the map

// Structure to represent a cell in the map
struct Cell {
    char symbol; // Symbol representing the cell
    bool visited; // Flag indicating if the cell has been visited
};

// Function to generate a random map
void generateMap(Cell map[MAX_ROWS][MAX_COLS]) {
    srand(time(NULL)); // Seed the random number generator

    // Fill the map with random symbols
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            // Generate a random symbol ('.' for empty cell, '#' for obstacle)
            map[i][j].symbol = rand() % 2 == 0 ? '.' : '#';
            map[i][j].visited = false; // Initialize visited flag to false
        }
    }
}

// Function to display the map
void displayMap(Cell map[MAX_ROWS][MAX_COLS]) {
    // Display the map
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << map[i][j].symbol << " ";
        }
        cout << endl;
    }
}

// Function to save the map to a file
void saveMapToFile(Cell map[MAX_ROWS][MAX_COLS], const string& filename) {
    ofstream outFile(filename);

    // Write the map to the file
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            outFile << map[i][j].symbol << " ";
        }
        outFile << endl;
    }

    outFile.close();
}

// Function to load the map from a file
void loadMapFromFile(Cell map[MAX_ROWS][MAX_COLS], const string& filename) {
    ifstream inFile(filename);

    // Read the map from the file
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            inFile >> map[i][j].symbol;
            map[i][j].visited = false; // Reset visited flag
        }
    }

    inFile.close();
}

int main() {
    Cell map[MAX_ROWS][MAX_COLS];
    char choice;

    cout << "Welcome to Map Navigator!" << endl;

    // Ask the user if they want to generate a new map or load an existing one
    cout << "Do you want to (G)enerate a new map or (L)oad an existing one? (G/L): ";
    cin >> choice;

    // Generate a new map or load an existing one based on user choice
    if (choice == 'G' || choice == 'g') {
        generateMap(map);
    } else if (choice == 'L' || choice == 'l') {
        loadMapFromFile(map, "map.txt");
    } else {
        cout << "Invalid choice. Exiting program." << endl;
        return 1;
    }

    // Display the map
    cout << "Map:" << endl;
    displayMap(map);

    // Save the map to a file if it's a new map
    if (choice == 'G' || choice == 'g') {
        saveMapToFile(map, "map.txt");
        cout << "Map saved to 'map.txt'" << endl;
    }

    return 0;
}
