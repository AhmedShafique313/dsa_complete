#include <iostream>
#include <stack>
using namespace std;

const int N = 5; // Size of the maze

struct Point {
    int x, y;
};

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

void printMaze(int maze[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
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

bool solveMaze(int maze[N][N], Point start, Point end) {
    if (!isSafe(maze, start.x, start.y) || !isSafe(maze, end.x, end.y)) return false;

    stack<Point> s;
    s.push(start);

    while (!s.empty()) {
        Point current = s.top();
        s.pop();

        maze[current.x][current.y] = 2; // Mark as part of the path

        if (current.x == end.x && current.y == end.y) {
            maze[start.x][start.y] = 3; // Mark start
            maze[end.x][end.y] = 4; // Mark end
            printMaze(maze);
            return true;
        }

        // Move down
        if (isSafe(maze, current.x + 1, current.y)) {
            Point down = {current.x + 1, current.y};
            s.push(down);
        }

        // Move right
        if (isSafe(maze, current.x, current.y + 1)) {
            Point right = {current.x, current.y + 1};
            s.push(right);
        }
    }

    cout << "No path found!" << endl;
    return false;
}

int main() {
    int maze[N][N];
    cout << "Enter the maze (use ' ' for open cells and '#' for blocked cells):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char cell;
            cin >> cell;
            if (cell == ' ')
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

    if (!solveMaze(maze, start, end)) {
        cout << "No path exists!" << endl;
    }

    return 0;
}
