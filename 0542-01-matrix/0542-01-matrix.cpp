class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto p = q.front();
            
            int row = p.first.first;
            int col = p.first.second;
            int steps = p.second;
            dis[row][col] = steps;
            q.pop();
            
            for(int i= 0; i<4; i++)
            {
                int nrow = row+dRow[i];
                int ncol = col+dCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                  && vis[nrow][ncol] == 0)
                {
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dis;
    }
};