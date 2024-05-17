#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int MAX_ROWS = 10; // Maximum number of rows in the map
const int MAX_COLS = 10; // Maximum number of columns in the map
const int INF = 1e9; // Represents infinity

// Structure to represent a cell in the map
struct Cell {
    int row, col; // Row and column indices of the cell
    char symbol; // Symbol representing the cell
    bool visited; // Flag indicating if the cell has been visited
    int distance; // Distance from the starting point
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
            map[i][j].distance = INF; // Initialize distance to infinity
            map[i][j].row = i; // Assign row index
            map[i][j].col = j; // Assign column index
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

// Function to find shortest distance using Dijkstra's algorithm
int dijkstra(Cell map[MAX_ROWS][MAX_COLS], int startRow, int startCol, int endRow, int endCol) {
    // Define a min heap priority queue to store cells based on their distances
    priority_queue<pair<int, Cell*>, vector<pair<int, Cell*>>, greater<pair<int, Cell*>>> pq;

    // Set distance of starting point to 0 and push it to the priority queue
    map[startRow][startCol].distance = 0;
    pq.push({0, &map[startRow][startCol]});

    while (!pq.empty()) {
        // Extract the cell with minimum distance from the priority queue
        Cell* current = pq.top().second;
        pq.pop();

        // Mark the current cell as visited
        current->visited = true;

        // If the current cell is the destination, return its distance
        if (current->row == endRow && current->col == endCol) {
            return current->distance;
        }

        // Explore the neighboring cells
        int dr[] = {-1, 0, 1, 0}; // Directions: up, right, down, left
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int newRow = current->row + dr[i];
            int newCol = current->col + dc[i];

            // Check if the neighboring cell is within bounds and not an obstacle
            if (newRow >= 0 && newRow < MAX_ROWS && newCol >= 0 && newCol < MAX_COLS && map[newRow][newCol].symbol != '#') {
                int newDistance = current->distance + 1; // Assuming each step has unit distance

                // Update the distance of the neighboring cell if it's shorter than the current distance
                if (newDistance < map[newRow][newCol].distance) {
                    map[newRow][newCol].distance = newDistance;
                    pq.push({newDistance, &map[newRow][newCol]});
                }
            }
        }
    }

    // If destination is not reachable, return -1
    return -1;
}

int main() {
    Cell map[MAX_ROWS][MAX_COLS];

    // Generate a random map
    generateMap(map);

    // Display the map
    cout << "Map:" << endl;
    displayMap(map);

    // Get input for starting and ending points
    int startRow, startCol, endRow, endCol;
    cout << "Enter starting point (row col): ";
    cin >> startRow >> startCol;
    cout << "Enter ending point (row col): ";
    cin >> endRow >> endCol;

    // Calculate shortest distance using Dijkstra's algorithm
    int shortestDistance = dijkstra(map, startRow, startCol, endRow, endCol);

    // Display the shortest distance
    if (shortestDistance != -1) {
        cout << "Shortest distance from starting point to ending point: " << shortestDistance << endl;
    } else {
        cout << "Destination is not reachable from the starting point." << endl;
    }

    return 0;
}
