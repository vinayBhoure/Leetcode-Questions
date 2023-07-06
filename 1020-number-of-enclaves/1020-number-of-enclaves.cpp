class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
       
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j] == 1 && vis[i][j] == 0)
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
       
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto p =q.front();
            int r = p.first;
            int c = p.second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int nrow = r+dRow[i];
                int ncol = c+dCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                  && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        int land = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 1)
                {
                    land++;
                }
            }
        }
        return land;
    }
};