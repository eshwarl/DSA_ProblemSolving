class Solution {
    private:
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        int perimeter=0;
        for(int d=0;d<4;d++){
            int nrow=row+drow[d];
            int ncol=col+dcol[d];
            if(nrow<0||nrow>=n||ncol<0||ncol>=m){
                 perimeter++;
            }else if(grid[nrow][ncol]==0){
                  perimeter++;
            } else if (!vis[nrow][ncol]){
                perimeter+=dfs(nrow,ncol,grid,vis);
            }
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return dfs(i,j,grid,vis);
                }
            }
        }
        return 0;

        
    }
};