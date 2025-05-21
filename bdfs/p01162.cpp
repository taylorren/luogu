#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y, int n)
{
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || matrix[x][y] == 1)
    {
        return;
    }
    visited[x][y] = true;
    dfs(matrix, visited, x + 1, y, n);
    dfs(matrix, visited, x - 1, y, n);
    dfs(matrix, visited, x, y + 1, n);
    dfs(matrix, visited, x, y - 1, n);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Mark all 0s connected to the boundary
    for (int i = 0; i < n; ++i)
    {
        if (matrix[i][0] == 0 && !visited[i][0])
            dfs(matrix, visited, i, 0, n);
        if (matrix[i][n - 1] == 0 && !visited[i][n - 1])
            dfs(matrix, visited, i, n - 1, n);
    }
    for (int j = 0; j < n; ++j)
    {
        if (matrix[0][j] == 0 && !visited[0][j])
            dfs(matrix, visited, 0, j, n);
        if (matrix[n - 1][j] == 0 && !visited[n - 1][j])
            dfs(matrix, visited, n - 1, j, n);
    }

    // Fill enclosed 0s with 2
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0 && !visited[i][j])
            {
                matrix[i][j] = 2;
            }
        }
    }

    // Output the result
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}