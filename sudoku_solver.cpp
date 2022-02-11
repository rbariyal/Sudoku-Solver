#include<bits/stdc++.h>
#define N 9
using namespace std;
bool isvalid(int **grid, int i, int j, int val)
{
    for (int k = 0; k < N; k++)
    {
        if (grid[i][k] == val)
        {
            return false;
        }
    }
    for (int k = 0; k < N; k++)
    {
        if (grid[k][j] == val)
        {
            return false;
        }
    }
    int srow = i - (i % 3);
    int scol = j - (j % 3);
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if (grid[srow + k][scol + l] == val)
            {
                return false;
            }
        }
    }
    return true;
}
void show(int **grid)
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(int **grid, int i, int j)
{
    if (i == N - 1 && j == N)
    {
    show(grid);
        return;
    }
    if (j == N)
    {
        i++;
        j = 0;
    }
    if(grid[i][j]!=0)
    {
        solve(grid,i,j+1);
    }
    if (grid[i][j] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isvalid(grid, i, j, num))
            {
                grid[i][j] = num;
                solve(grid, i, j + 1);
                grid[i][j] = 0;
            }
        }
    }
}

int main()
{
    // int g[][N] =  {{3, 0, 6, 5, 0, 8, 4, 0, 0},
    //                {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //                {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //                {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //                {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //                {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //                {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //                {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    int *g[N];
    cout << "Enter the array " << '\n';
    for (int i = 0; i < N; i++)
        g[i] = new int[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> g[i][j];
    solve(g,0,0);
 
    return 0;
}

// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0

