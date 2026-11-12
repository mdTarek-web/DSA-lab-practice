#include <iostream>
#include <vector>
using namespace std;

void dfsIsland(vector<vector<int>>& grid, int r, int c)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Check boundary and water
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1)
        return;

    // Mark as visited
    grid[r][c] = 0;

    // Down
    dfsIsland(grid, r + 1, c);

    // Up
    dfsIsland(grid, r - 1, c);

    // Right
    dfsIsland(grid, r, c + 1);

    // Left
    dfsIsland(grid, r, c - 1);
}

int numIslands(vector<vector<int>>& grid)
{
    int count = 0;

    for (int r = 0; r < (int)grid.size(); r++)
    {
        for (int c = 0; c < (int)grid[0].size(); c++)
        {
            if (grid[r][c] == 1)
            {
                dfsIsland(grid, r, c);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    int result = numIslands(grid);

    cout << "Number of islands: " << result << endl;

    return 0;
}