class Solution {
public:
    vector<int> solve(vector<int>& nums) {
       map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<int> vec;
        for(auto it: mp){
            if(it.second > 1) vec.push_back(it.first);
        }
        return vec;
    }
    
    vector<int> findDuplicates(vector<int>& nums){
        vector<int> vec;
        for(int i=0; i<nums.size(); i++){
            int num = abs(nums[i]);
            int index = num-1;
            
            if(nums[index] < 0) vec.push_back(abs(nums[i]));
            else nums[index] = -nums[index];
        }
        return vec;
    }
};