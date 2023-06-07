class Solution {
    public:
    void printCS(int i, int target, vector<int>& arr, vector <int>&ds,  vector <vector<int>> &ans)
    {
        if(i == arr.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(arr[i]<=target)
        {
        ds.push_back(arr[i]);
        printCS(i,target - arr[i], arr,ds,ans);
        ds.pop_back();
        }
        
        printCS(i+1,target, arr,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector <vector<int>> ans;
        vector <int> ds;
        printCS(0,target,candidates,ds,ans);
        
        return ans;
    }
};