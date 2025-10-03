class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        int perimeter = 0;

        for (int d = 0; d < 4; d++) {
            int newRow = row + delRow[d];
            int newCol = col + delCol[d];

            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) {
                perimeter++;
            }
            else if (grid[newRow][newCol] == 0) {
                perimeter++;
            }
            else if (!vis[newRow][newCol]) {
                perimeter += dfs(newRow, newCol, grid, vis);
            }
        }

        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid, vis);
                }
            }
        }

        return 0;
    }
};
