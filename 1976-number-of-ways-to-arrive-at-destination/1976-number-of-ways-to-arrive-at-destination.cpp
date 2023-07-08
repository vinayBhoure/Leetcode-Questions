class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int,int>> adj[n];
    for(auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
        
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> q;
    q.push({0,0});
    vector<long long> dist(n, 1e18); // Changed from int to long long
    vector<long long> way(n,0); // Changed from int to long long
    dist[0] = 0;
    way[0] = 1;
    int mod = (int)(1e9 + 7);
        
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
            
        int node = p.second; // Changed from p.first to p.second
        long long dis = p.first; // Changed from p.second to p.first
            
        if(dis > dist[node]) {
            continue;
        }
            
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int eW = it.second;
                
            if(dis+eW < dist[adjNode]) {
                dist[adjNode] = dis+eW;
                way[adjNode] = way[node]%mod;
                q.push({dist[adjNode], adjNode}); // Changed the order of elements in the pair
            }
            else if(dis+eW == dist[adjNode]) {
                way[adjNode] = (way[adjNode]+way[node])%mod;
            }
        }
    }
    return way[n-1]%mod;
}

};