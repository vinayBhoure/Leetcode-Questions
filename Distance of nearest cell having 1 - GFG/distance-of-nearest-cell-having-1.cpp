//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	      int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 1)
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends