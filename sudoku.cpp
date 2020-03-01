#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        // cout << "\n";
    }
    // cout << "\n";
}
bool isValid(vector<vector<int>> sudoku, int i, int j)
{
    // cout << "kya hua\n";
    // checking in row
    for (int idx = 0; idx < 9; idx++)
    {
        if (idx != j)
        {
            if (sudoku[i][j] == sudoku[i][idx])
            {
                return false;
            }
        }
    }

    // checking in column
    for (int idx = 0; idx < 9; idx++)
    {
        if (idx != i)
        {
            if (sudoku[i][j] == sudoku[idx][j])
            {
                return false;
            }
        }
    }

    // checking in 3x3 box
    int I = (i / 3) * 3;
    int J = (j / 3) * 3;
    // checking north west
    for (int row = i - 1, col = j - 1; row >= I && col >= J; row--, col--)
    {
        if (sudoku[row][col] == sudoku[i][j])
        {
            return false;
        }
    }

    // checking north east
    for (int row = i - 1, col = j + 1; row >= I && col <= J + 2; row--, col++)
    {
        if (sudoku[row][col] == sudoku[i][j])
        {
            return false;
        }
    }

    // checking south east
    for (int row = i + 1, col = j + 1; row <= I + 2 && col <= J + 2; row++, col++)
    {
        if (sudoku[row][col] == sudoku[i][j])
        {
            return false;
        }
    }

    //check south west
    for (int row = i + 1, col = j - 1; row <= I + 2 && col >= J; row++, col--)
    {
        if (sudoku[row][col] == sudoku[i][j])
        {
            return false;
        }
    }

    // if every condition above says that the element is unique
    return true;
}
bool solveSudoku(vector<vector<int>> &sudoku, int i, int j)
{
    // cout << "i  = " << i << " j = " << j << "\n";
    if (i == 9)
    {
        return true;
    }
    bool result = false;
    if (sudoku[i][j] == 0)
    {
        for (int idx = 1; idx <= 9; idx++)
        {
            sudoku[i][j] = idx;
            // print(sudoku);
            if (isValid(sudoku, i, j))
            {
                if (j == 8)
                {
                    result = solveSudoku(sudoku, i + 1, 0);
                }
                else
                {
                    result = solveSudoku(sudoku, i, j + 1);
                }

                if (result == true)
                {
                    return true;
                }
            }
        }
        sudoku[i][j] = 0;
        // print(sudoku);
        return false;
    }
    else
    {
        if (j == 8)
        {
            result = solveSudoku(sudoku, i + 1, 0);
        }
        else
        {
            result = solveSudoku(sudoku, i, j + 1);
        }
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> sudoku(9, vector<int>(9));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> sudoku[i][j];
            }
        }
        if (solveSudoku(sudoku, 0, 0) == true)
        {
            print(sudoku);
        }
        else
        {
            cout << -1;
        }
        cout << "\n";
    }
}
