class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);
        
        // Step 1: Count ones in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        
        // Step 2: Compute diff matrix
        vector<vector<int>> diff(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - m - n;
            }
        }
        
        return diff;
    }
};
