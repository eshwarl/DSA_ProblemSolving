class Solution {
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        // initial configurations
         int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int area=1;
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
        for(int dir=0;dir<4;dir++){
  int nr=i+dr[dir];
  int nc=j+dc[dir];
  if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
    area+=dfs(nr,nc,grid,vis);
  }
      }
      return area;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
      vector<vector<int>>vis(n,vector<int>(m,0));
      int maxArea=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                int area=dfs(i,j,grid,vis);
                maxArea=max(maxArea,area);
            }
        }
      }
      return maxArea;
    }
};