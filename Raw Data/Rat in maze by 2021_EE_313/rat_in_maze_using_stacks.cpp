#include <iostream>
#include <stack>
using namespace std;

struct Point {
    int x, y;
};

bool isSafetoMove(int** maze, int M, int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < M && maze[x][y] == 1);
}

void printMazeOutput(int** maze, int M) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (maze[i][j] == 0)
                cout << " 0 ";
            else if (maze[i][j] == 1)
                cout << " 1 ";
            else if (maze[i][j] == 2)
                cout << " - ";
            else if (maze[i][j] == 3)
                cout << " S ";
            else if (maze[i][j] == 4)
                cout << " E ";
        }
        cout << endl;
    }
}

void printMazeIutput(int** maze, int M) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (maze[i][j] == 0)
                cout << " 0 ";
            else if (maze[i][j] == 1)
                cout << " 1 ";
            else if (maze[i][j] == 2)
                cout << " - ";
            else if (maze[i][j] == 3)
                cout << " 1 ";
            else if (maze[i][j] == 4)
                cout << " 1 ";
        }
        cout << endl;
    }
}

bool solveMaze(int** maze, int M, Point start, Point end) {
    if (!isSafetoMove(maze, M, start.x, start.y) || !isSafetoMove(maze, M, end.x, end.y)) return false;

    stack<Point> solve;
    solve.push(start);

    while (!solve.empty()) {
        Point temp = solve.top();
        solve.pop();

        maze[temp.x][temp.y] = 2; // Mark as part of the path

        if (temp.x == end.x && temp.y == end.y) {
            maze[start.x][start.y] = 3; // Mark start
            maze[end.x][end.y] = 4; // Mark end
            printMazeOutput(maze,M);
            return true;
        }

        // Move down
        if (isSafetoMove(maze, M, temp.x + 1, temp.y)) {
            Point down = {temp.x + 1, temp.y};
            solve.push(down);
        }

        // Move right
        if (isSafetoMove(maze, M, temp.x, temp.y + 1)) {
            Point right = {temp.x, temp.y + 1};
            solve.push(right);
        }
    }

    cout << "I am stuck in it !!!!!" << endl;
    return false;
}

int main() {
    const int size = 8;
    int mazeData[size][size] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int** problem = new int*[size];
    for (int i = 0; i < size; ++i) {
        problem[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            problem[i][j] = mazeData[i][j];
        }
    }

    Point start = {1, 1}; // Start point
    Point end = {6, 6};   // End point
    cout<<"This is the input Maze.................."<<endl;
    printMazeIutput(problem, size);
    
    cout<<"This is the solved Maze.................."<<endl;
    if (!solveMaze(problem, size, start, end)) {
        cout << "There is no path to escape!" << endl;
    }

    // Free memory
    for (int i = 0; i < size; ++i) {
        delete[] problem[i];
    }
    delete[] problem;

    return 0;
}
