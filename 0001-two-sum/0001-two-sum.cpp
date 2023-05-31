class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
   
      vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) 
    {
      if (m.find(target - nums[i]) != m.end())
      {
        v.push_back(m[target - nums[i]]);
        v.push_back(i);
        return v;
      } 
        else
          m[nums[i]] = i;
    }
    return v;

    //         vector<int> ans;
    //         map<int,int> mp;

    //         for(int i=0; i<nums.size();i++)
    //         {
    //             int ntf = target - nums[i];

    //             if(mp.find(ntf) != mp.end())
    //             {
    //                 ans.push_back(mp[nums[i]] +1);
    //                 ans.push_back(i+1);
    //                 return ans;
    //             }

    //             mp[nums[i]] = i;
    //         }

    //         return ans;

    //         int i =0;
    //         int j = nums.size() -1;
    //         vector<int> ans;
    //         sort(nums.begin(), nums.end());

    //         while(i<j)
    //         {
    //             if(nums[i] + nums[j] > target)
    //             {
    //                 j--;
    //             }
    //             else if(nums[i] + nums[j] < target)
    //             {
    //                 i++;
    //             }
    //             else if(nums[i] + nums[j] == target){
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //             }
    //         }
    //         return ans;
  }
};