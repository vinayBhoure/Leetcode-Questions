class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1,0);
        for(int i=0; i<n ;i++) parent[i]=i;
        size.resize(n+1,1);
    }
    
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionbySize(int u, int v)
    {
        int ulm_u = findParent(u);
        int ulm_v = findParent(v);
        if(ulm_u == ulm_v) return;
        if(size[ulm_u] < size[ulm_v])
        {
            parent[ulm_u] = ulm_v;
            size[ulm_v] += size[ulm_u];
        }else{
            parent[ulm_v] = ulm_u;
            size[ulm_u] += size[ulm_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mailNode;
        int n = accounts.size();
        DisjointSet ds(n);
        
        for(int i=0; i<n; i++)
        {
            for(int j = 1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mailNode.find(mail) == mailNode.end())
                {
                    mailNode[mail] = i;
                }else{
                    ds.unionbySize(i, mailNode[mail]);
                }
            }
        }
          
        vector<string> mergedMail[n];
        for(auto it:mailNode)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++)
        {
            if(mergedMail[i].size() == 0)
            {
                continue;
            }
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};