/* class DisjointSet{
public:
    vector<int> size,parent;
    //constructor
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1, 0);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int findParent(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionbySize(int u, int v)
    {
        int ulm_u = findParent(u);
        int ulm_v = findParent(v);
        if(ulm_u == ulm_v) return;
        if(size[ulm_u] < size[ulm_v]){
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
//step-1
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == 0) continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int i=0; i<4; i++)
                {
                    int nr = row+dr[i];
                    int nc = col+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n){
                        if(grid[nc][nr]==1)
                    {
                        ds.unionbySize(row*n+col, nr*n+nc);
                    }
                    }
                
                }
            }
        }
//step-2
        int maxi = 0;
             for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == 1) continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int> components;
                for(int i=0; i<4; i++)
                {
                    int nr = row+dr[i];
                    int nc = col+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n){
                         if(grid[nc][nr]==1){
                        components.insert(ds.findParent(nr*n+nc));
                         }
                    }
                    
                }
            
                 int totalSize = 1;
                 for(auto it: components){
                     totalSize = totalSize + ds.size[it];
                 }
                 maxi = max(maxi, totalSize);
            }
           }
                 
        for(int i=0; i<n*n; i++)
        {
            maxi = max(maxi, ds.size[ds.findParent(i)]);
        }
                       return maxi;
    }
}; */

class DisjointSet{
		
	public:
    vector<int>rank,parent,size;
		DisjointSet(int n)
		{
			rank.resize(n+1,0); //in case if its 1 based indexing
			size.resize(n+1);
			parent.resize(n+1);
			for(int i=0;i<n;i++) //till n if 1 based indexing
			{
				parent[i] = i;
				size[i]=1;
			}
		}

		int findUParent(int node) //path compression
		{
			if(node==parent[node]){
				return node;
			}
			return parent[node] = findUParent(parent[node]);
		}

		void unionByRank(int u,int v)
		{
			int ult_pu = findUParent(u);
			int ult_pv = findUParent(v);
			if(ult_pv == ult_pu) return;
			if(rank[ult_pv]>rank[ult_pu]){
				parent[ult_pu] = ult_pv;
			}
			else if(rank[ult_pv]<rank[ult_pu]){
				parent[ult_pv] = ult_pu;
			}
			else //rank same h
			{
				parent[ult_pv] = ult_pu; //kisi ko bhi add kr do
				rank[ult_pu]++;
			}
		}

		void unionBySize(int u,int v) //more intutive than rank 
		{
			int ult_pu = findUParent(u);
			int ult_pv = findUParent(v);
			if(ult_pv == ult_pu) return;
			if(size[ult_pv]>size[ult_pu])
			{
				parent[ult_pu] = ult_pv;
				size[ult_pv] += size[ult_pu];
			}
			else{
				parent[ult_pv] = ult_pu;
				size[ult_pu] += size[ult_pv];
			}
		}
	};

class Solution {
    private:
    bool isValid(int row, int col, int n){
        return (row>=0 && row<n && col>=0 && col<n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        //step-1
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    continue;
                }
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow = row+delrow[i];
                    int ncol = col+delcol[i];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol]==1){
                            int rowNo = row*n+col;
                            int adjRowNo = nrow*n+ncol;
                            ds.unionBySize(rowNo,adjRowNo);
                        }
                    }
                }
            }
        }
        //step-2
        
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,1,0,-1};
                set<int>components;
                for(int i=0;i<4;i++){
                    int nrow = row+delrow[i];
                    int ncol = col+delcol[i];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol]==1){
                            components.insert(ds.findUParent(nrow*n+ncol));
                        }
                    }
                }
                int cost=1; //ek khud bhi to h 
                for(auto it: components){
                    cost+=ds.size[it];
                }
                ans = max(ans,cost);

            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++){
            ans = max(ans,ds.size[ds.findUParent(cellNo)]);
        }
        return ans;
    }
};