//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool detectCycle(int src, int vis[], vector<int> adj[])
  {
      vis[src] = 1;
      queue<pair<int,int>> q;
      q.push({src,-1});
      
      while(!q.empty())
      {
          auto p = q.front();
          int node = p.first;
          int parent = p.second;
          q.pop();
          for(auto adjnode : adj[node])
          {
              if(!vis[adjnode])
              {
                 q.push(make_pair(adjnode,node));
                 vis[adjnode]=1;
              }
              else if(parent != adjnode)
              {
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detectCycle(i, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends