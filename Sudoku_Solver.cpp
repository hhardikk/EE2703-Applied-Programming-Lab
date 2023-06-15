#include <iostream>
using namespace std;

bool checker(int board[9][9], int x, int y, int check)
{
    int res_x = x / 3;
    int res_y = y / 3;

    for (int i = res_x * 3; i < (res_x + 1) * 3; i++)
    {
        for (int j = res_y * 3; j < (res_y + 1) * 3; j++)
        {
            if (board[i][j] == check)
                return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == check)
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == check)
            return false;
    }

    return true;
}

bool sudoku(int board[9][9], int row, int column)
{
    if ((row == 8) && (column == 9))
    {
        return true;
    }

    if (column == 9)
    {
        row++;
        column = 0;
    }

    if (board[row][column] > 0)
    {
        return sudoku(board, row, column + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (checker(board, row, column, i))
        {
            board[row][column] = i;
            if (sudoku(board, row, column + 1))
            {
                return true;
            }
        }
        board[row][column] = 0;
    }
    return false;
}


bool SolveSudoku(int board[9][9])
{
    int row = 0;
    int column = 0;

    if (sudoku(board, row, column))
        return true;

    return false;
}

// Function to print grids of the Sudoku.
void printGrid(int board[9][9])
{
    if (SolveSudoku(board))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n = 9;
    int arr[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    printGrid(arr);
}