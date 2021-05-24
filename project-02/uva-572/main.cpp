#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int row, int col, vector<string> &grid)
{
    static const vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static const vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

    grid[row][col] = '.';

    for (int i = 0; i < 8; ++i)
    {
        int tr = row + dr[i];
        int tc = col + dc[i];

        if (0 <= tr && tr < int(grid.size()) && 0 <= tc &&
            int(grid[0].length()) && grid[tr][tc] == '@')
        {
            dfs(tr, tc, grid);
        }
    }
}

int main()
{
    for (int h, w; cin >> h >> w && h != 0 && w != 0;)
    {
        vector<string> grid(h);
        for (int i = 0; i < h; ++i)
        {
            cin >> grid[i];
        }

        int components = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (grid[i][j] == '@')
                {
                    ++components;
                    dfs(i, j, grid);
                }
            }
        }

        cout << components << "\n";
    }
}
