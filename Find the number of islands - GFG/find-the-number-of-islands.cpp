//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bsf(int row, int col, vector<vector<char>> grid, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty())
        {
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();
            
            for(int drow = -1; drow<=1; drow++)
            {
                for(int dcol = -1; dcol<=1; dcol++)
                {
                    int nrow = drow+row;
                    int ncol = dcol+col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                       grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
                    {
                        vis[nrow][ncol]=1;
                        q.push(make_pair(nrow,ncol));
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int row = 0; row<n; row++)
        {
            for(int col = 0; col<m; col++)
            {
                if(!vis[row][col] && grid[row][col] == '1')
                {
                        cnt++;
                    bsf(row,col,grid,vis);
                
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends