class Solution {
    private:
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis){
        int n=board.size();
        int m=board[0].size();
        vis[i][j]=1;
        int dr[4]={-1,+1,0,0};
        int dc[4]={0,0,-1,+1};
        for(int dir=0;dir<4;dir++){
            int nr=i+dr[dir];
            int nc=j+dc[dir];
            if(nr>=0 && nr<n&& nc>=0&&nc<m&& board[nr][nc]=='X'&&vis[nr][nc]==0){
                dfs(nr,nc,board,vis);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
      int cnt=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='X'&& vis[i][j]==0){
                cnt++;
                dfs(i,j,board,vis);
            }
        }
      }
      return cnt;
    }
};