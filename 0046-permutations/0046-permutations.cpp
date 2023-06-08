class Solution {
public:
    void allPerm(vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int map[])
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i =0; i<nums.size(); i++)
        {
            if(map[i] == 0)
            {
                ds.push_back(nums[i]);
                map[i] = 1;
                allPerm(ds,ans,nums,map);
                map[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> appraoch1(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int map[nums.size()];
        for(int i=0; i<nums.size(); i++) map[i]=0;
        allPerm(ds,ans,nums,map);
        return ans;
    }
        
        
    vector<vector<int>> permute(vector<int>& nums) {
        
        return appraoch1(nums);
    }
};