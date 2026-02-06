class Solution {
    private:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
      int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
            
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;

        
    }
};