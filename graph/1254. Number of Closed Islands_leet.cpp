 vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(i==0 || i==m-1 || j==0 || j==n-1){
                  dfs(i,j,grid);
               }
           }
       }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
    
    void dfs(int r,int c,vector<vector<int>>& grid){
        if(!isValid(r,c,grid))return;
        grid[r][c]=1;
        for(int i=0;i<dir.size();i++){
            int nr=r+dir[i].first;
            int nc=c+dir[i].second;
                dfs(nr,nc,grid);
        }
    }
    
    bool isValid(int i,int j,vector<vector<int>>& grid){
         int m=grid.size();
        int n=grid[0].size();
        return (i>=0 && j>=0 && i<m && j<n && grid[i][j]==0);
    }