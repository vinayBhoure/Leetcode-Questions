class Solution {
public:
    void subset(int i, int n, vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds)
    {
        ans.push_back(ds);
        
         for (int j = i; j < nums.size(); j++) {
    if (j != i && nums[j] == nums[j - 1]) continue;
    ds.push_back(nums[j]);
    subset(j + 1, n, ans, nums, ds);
    ds.pop_back();
  }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        subset(0,nums.size(),ans,nums,ds);
        return ans;
    }
};