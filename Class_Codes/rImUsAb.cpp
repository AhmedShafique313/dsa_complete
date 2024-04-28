#include <iostream>
#include <stack>
using namespace std;

struct Point {
    int x, y;
};

bool isSafe(int** maze, int size, int x, int y) {
    return (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1);
}

void printMaze(int** maze, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (maze[i][j] == 0)
                cout << "█ ";
            else if (maze[i][j] == 1)
                cout << "  ";
            else if (maze[i][j] == 2)
                cout << "* ";
            else if (maze[i][j] == 3)
                cout << "S ";
            else if (maze[i][j] == 4)
                cout << "E ";
        }
        cout << endl;
    }
}

bool solveMaze(int** maze, int size, Point start, Point end) {
    if (!isSafe(maze, size, start.x, start.y) || !isSafe(maze, size, end.x, end.y)) return false;

    stack<Point> s;
    s.push(start);

    while (!s.empty()) {
        Point current = s.top();
        s.pop();

        maze[current.x][current.y] = 2; // Mark as part of the path

        if (current.x == end.x && current.y == end.y) {
            maze[start.x][start.y] = 3; // Mark start
            maze[end.x][end.y] = 4; // Mark end
            printMaze(maze, size);
            return true;
        }

        // Move down
        if (isSafe(maze, size, current.x + 1, current.y)) {
            Point down = {current.x + 1, current.y};
            s.push(down);
        }

        // Move right
        if (isSafe(maze, size, current.x, current.y + 1)) {
            Point right = {current.x, current.y + 1};
            s.push(right);
        }
    }

    cout << "No path found!" << endl;
    return false;
}

int main() {
    int size;
    cout << "Enter the size of the maze: ";
    cin >> size;

    int** maze = new int*[size];
    for (int i = 0; i < size; ++i) {
        maze[i] = new int[size];
    }

    cout << "Enter the maze row by row (use ' ' for open cells and '#' for blocked cells):\n";
    for (int i = 0; i < size; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < size; ++j) {
            if (row[j] == ' ')
                maze[i][j] = 1; // Open cell
            else
                maze[i][j] = 0; // Blocked cell
        }
    }

    Point start, end;
    cout << "Enter the starting point (x y): ";
    cin >> start.x >> start.y;
    cout << "Enter the ending point (x y): ";
    cin >> end.x >> end.y;

    if (!solveMaze(maze, size, start, end)) {
        cout << "No path exists!" << endl;
    }

    // Free memory
    for (int i = 0; i < size; ++i) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
