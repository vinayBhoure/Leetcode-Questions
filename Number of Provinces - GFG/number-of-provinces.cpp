//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(int node, vector<int> adj[], int vis[])
  {
      vis[node] = 1;
      
      for(auto it:adj[node])
      {
          if(!vis[it])
          {
              dfs(it,adj,vis);
          }
      }
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> list[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1 && i!=j)
                {
                    list[i].push_back(j);
                    list[i].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int cnt = 0;
        
        for(int i =0; i<V; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,list,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends