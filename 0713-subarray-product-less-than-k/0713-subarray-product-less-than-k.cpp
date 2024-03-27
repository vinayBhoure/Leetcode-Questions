class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        long long product = 1;
        int end=0;
        int start=0;
        int ans=0;
        while(end<n && start<n){
            product = product*nums[end];
           
            
            while(start<=end && product>=k){
                product = product/nums[start];
                start++;
            }
            
            
            ans = ans+end-start+1;
            end++;
        }

        return ans;
    }
    
};