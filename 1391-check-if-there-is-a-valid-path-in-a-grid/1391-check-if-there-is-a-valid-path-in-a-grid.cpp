class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
     
        vector<vector<vector<int>>> dirs = {
            {},
            {{0,-1},{0,1}},     
            {{-1,0},{1,0}},     
            {{0,-1},{1,0}},     
            {{0,1},{1,0}},      
            {{0,-1},{-1,0}},    
            {{0,1},{-1,0}}      
        };
        
      
        auto isValid = [&](int x, int y, int px, int py) {
            for (auto &d : dirs[grid[x][y]]) {
                if (x + d[0] == px && y + d[1] == py)
                    return true;
            }
            return false;
        };
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            if(i == m-1 && j == n-1) return true;
            
            for(auto &d : dirs[grid[i][j]]) {
                int ni = i + d[0];
                int nj = j + d[1];
                
                if(ni >= 0 && nj >= 0 && ni < m && nj < n && !vis[ni][nj]) {
                    
               
                    if(isValid(ni, nj, i, j)) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        return false;
    }
};