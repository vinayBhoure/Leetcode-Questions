class Solution {
public:
    int solve(vector<int> &nums){
        if (nums.empty()) 
        return 0;
        
      int prev = nums[0];
        int prev2 = 0;
        for(int i=0; i<nums.size(); i++){
            int pick = nums[i] + ((i > 1) ? prev2 : 0);
            int nonPick = prev;
            
            int curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() <= 1)
        return nums.empty() ? 0 : nums[0];
    
    vector<int> temp1(nums.begin() + 1, nums.end());
    vector<int> temp2(nums.begin(), nums.end() - 1);
        return max(solve(temp1), solve(temp2));
    }
};