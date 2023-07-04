//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
           int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
             
            }
        }
        
        int dRow[] = {-1,0,1,0};
            int dCol[] = {0,1,0,-1};
        int time = 0;
        while(!q.empty())
        {
            auto p = q.front();
            int row = p.first.first;
            int col = p.first.second;
            int t = p.second;
            q.pop();
            time = max(t,time);
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n 
                  && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2)
                {
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=2;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(visited[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;     
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends