class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
      // sort(nums.begin(), nums.end());
        int length = nums.size();
        
        // return nums[length - k];
      /*  priority_queue<int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
        */
         
        k = nums.size() - k + 1; 
        priority_queue<int> maxheap;
        
        for(int i=0; i<k;i++)
        {
            maxheap.push(nums[i]);
        }
        
        for(int i = k; i<nums.size(); i++)
        {
            if(nums[i] < maxheap.top())
            {
                maxheap.pop();
                maxheap.push(nums[i]);
            }
        }
      return maxheap.top();
    }
};