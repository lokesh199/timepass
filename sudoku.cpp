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
    }
    // cout << "\n";
}
bool isValid(vector<vector<int>> sudoku, int i, int j)
{
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
    int I = (i / 3) * 3, J = (j / 3) * 3;
    for (int idx = I; idx < I + 3; idx++)
    {
        for (int idx1 = J; idx1 < J + 3; idx1++)
        {
            if (idx != i || idx1 != j)
            {
                if (sudoku[i][j] == sudoku[idx][idx1])
                {
                    return false;
                }
            }
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
    bool result;
    if (sudoku[i][j] == 0)
    {
        for (int idx = 1; idx <= 9; idx++)
        {
            sudoku[i][j] = idx;
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
            }
            if (result == true)
            {
                return true;
            }
            else 
            {
                sudoku[i][j] = 0;
            }
        }
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
        if(solveSudoku(sudoku, 0, 0) == true)
        {
            print(sudoku);
        }
        cout << "\n";
    }
}
