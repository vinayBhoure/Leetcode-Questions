class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int N = numCourses;
    vector<int> adj[N];
         
         for(auto it : prerequisites)
         {
             adj[it[0]].push_back(it[1]);
         }
         
         vector<int> inD(N,0);
         for(int i=0; i<N; i++)
         {
             for(auto it :adj[i])
             {
                 inD[it]++;
             }
         }
         
         queue<int> q;
         for(int i=0; i<N; i++)
         {
             if(inD[i] == 0) q.push(i);
         }
         
         vector<int> topo;
         while(!q.empty())
         {
             int num = q.front();
             q.pop();
              topo.push_back(num);
             
             for(auto it: adj[num])
             {
                 inD[it]--;
                 if(inD[it] == 0)
                 {
                    q.push(it);
                 }
             }
         }
         if(topo.size() == N) return true;
         return false;
    }
};