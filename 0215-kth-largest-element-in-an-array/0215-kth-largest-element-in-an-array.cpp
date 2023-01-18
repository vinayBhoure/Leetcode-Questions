class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int length = nums.size();
        
        return nums[length - k];
        
    }
};