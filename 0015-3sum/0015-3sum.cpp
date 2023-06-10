class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
       int n = nums.size();
       set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            
            while(j<k){
              int  sum = nums[i] + nums[j] + nums[k];
                if(!sum){
                    vector<int> temp = { nums[i], nums[j], nums[k]};
                    ans.insert(temp);
                    j++;
                    k--;
                    
                    //  while (k > j && nums[k] == nums[k - 1]) k--;
                    // while (k > j && nums[j] == nums[j + 1]) j++;
                }
                 else if(sum > 0) k--;
                    else j++;
            }
        }
        vector<vector<int>> res{ans.begin(), ans.end()};
        return res;
    }
};