//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Defines the maze and calls the print_maze function to print the 2D array
//==============================================================

#include <iostream>
#include <array>
using namespace std;
#include "../include/maze.h"

int main() {
    // Declare position variable
    std::pair<int, int> position;

    // Define the maze
    array<array<string, 12>, 12> maze = {{
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", ".", ".", ".", "#", ".", ".", ".", ".", ".", ".", "#"},
        {".", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "x"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    }};

    array<array<string, COLS>, ROWS> maze1 = {{
            {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
            {"x", ".", ".", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
            {"#", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
            {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
            {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "#"},
            {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
            {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
            {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
            {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
            {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", ".", "#"}
        }};

    array<array<string, COLS>, ROWS> maze2 = {{
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "x", ".", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "#"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    }};

    print_maze(maze);

    // Find the initial position ("x")
    position = find_init(maze);  // Assign the result of find_init to the already declared position
    place_exit(maze);

    int start_row = position.first;
    int start_col = position.second;

    // Start the maze traversal from the initial position
    bool traverse_maze = traverseMaze(maze, start_row, start_col);

    if(traverse_maze){
        std::cout << "Maze solved! Reached the exit.\n";
    } else{
        std::cout << "No exit found :(\n";
    }

    return 0;
}
