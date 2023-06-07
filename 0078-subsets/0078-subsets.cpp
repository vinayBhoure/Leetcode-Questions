class Solution {
public:
    
    void subset(int i, int n, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(i == n)
        {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        subset(i+1,n,ds,nums,ans);
        ds.pop_back();
        
         subset(i+1,n,ds,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        subset(0,nums.size(),ds,nums,ans);
        return ans;
    }
};