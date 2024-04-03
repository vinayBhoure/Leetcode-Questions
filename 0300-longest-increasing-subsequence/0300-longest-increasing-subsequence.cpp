class Solution {
public:
    int solve(int idx, int ahead, int n, vector<int>&a, vector<vector<int>>&dp){
        if(idx < 0) return 0;
        
        if(dp[idx][ahead-1] != 1) return dp[idx][ahead-1];
        
        int not_take = solve(idx-1, ahead, n, a, dp);
        int take = -1e8;
        if(ahead == n || a[idx] < a[ahead]){
            take = 1 + solve(idx-1, idx, n, a, dp);
        }
        return dp[idx][ahead-1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                int take = -1e8;
                int notTake = dp[i - 1][j];
                if (j - 1 == n || nums[i - 1] < nums[j - 1])
                {
                    take = 1 + dp[i - 1][i];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n][n + 1];
    }
};