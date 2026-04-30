class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][c] = max score reaching (i,j) with cost c
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Starting point
        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // current cell cost & score
                int cost = (grid[i][j] == 0 ? 0 : 1);
                int score = grid[i][j];

                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    // move DOWN
                    if (i + 1 < m) {
                        int newCost = c + (grid[i+1][j] == 0 ? 0 : 1);
                        int newScore = dp[i][j][c] + grid[i+1][j];

                        if (newCost <= k) {
                            dp[i+1][j][newCost] = max(dp[i+1][j][newCost], newScore);
                        }
                    }

                    // move RIGHT
                    if (j + 1 < n) {
                        int newCost = c + (grid[i][j+1] == 0 ? 0 : 1);
                        int newScore = dp[i][j][c] + grid[i][j+1];

                        if (newCost <= k) {
                            dp[i][j+1][newCost] = max(dp[i][j+1][newCost], newScore);
                        }
                    }
                }
            }
        }

        // answer = max score at destination with cost ≤ k
        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m-1][n-1][c]);
        }

        return ans;
    }
};