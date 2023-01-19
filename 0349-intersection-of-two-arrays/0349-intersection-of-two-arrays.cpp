class Solution {
    private: 
    bool binarySearch(int target, vector<int> nums2)
    {
        int start = 0;
        int end = nums2.size() - 1;
        int mid = start + (end - start)/2;
        sort(nums2.begin(),nums2.end());
        
        while(start <= end)
        {
            if(nums2[mid] == target) return 1;
            
            else if(nums2[mid] > target)
            {
                end = mid - 1;
            }
            else{
                start = start +1;
            }
            mid = start + (end - start)/2;
        }
        return 0;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
       int l1 = nums1.size();
       int  l2 = nums2.size();
     
        set<int> s;
        
        for(int i = 0; i < l1; i++)
        {
            int target = nums1[i];
            if(binarySearch(target, nums2))
            {
                s.insert(nums1[i]);
            }
        }
        vector<int> ans;
        for (auto& it : s) {
        ans.push_back(it);
    }
        return ans;
    }
};