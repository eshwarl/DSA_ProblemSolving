class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O')
            return;

        board[r][c] = '#';

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            dfs(r + dr[d], c + dc[d], board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        // Left & Right borders
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }

        // Top & Bottom borders
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }

        // Final conversion
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
