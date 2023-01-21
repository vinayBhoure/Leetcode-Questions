class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int a = m-1;
        int b = n-1;
        for(int i = m+n-1; b >=0; i--)
        {
            if(a>=0 && nums1[a]>nums2[b])
            {
                nums1[i] = nums1[a];
                a--;
            }
            else{
                nums1[i] = nums2[b];
                b--;
            }
        }
        
    }
};