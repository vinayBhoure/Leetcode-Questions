class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int n = nums.size();
        int k = 0;
        int i =0;
        vector<int> ans;
        while(i<n)
        {
            if(i>0 && nums[i] == nums[i-1])
            {
                i++;
                k++;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        nums.clear();
        for(int i=0; i<ans.size(); i++)
        {
            nums.push_back(ans[i]);
        }
        return n-k;
    }
};