class Solution {
public:
    long long solve(int idx, vector<int> arr, int buy, vector<vector<int>> &dp){
        if(idx == arr.size()){
            return 0;
        }
        if(dp[idx][buy] != -1) return dp[idx][buy];
        long long profit = 0;
        if(buy){
            profit = max(-arr[idx] + solve(idx+1, arr, 0, dp) //pick
                      ,solve(idx+1,arr, 1, dp)); //nott-pick 
        }
        else{
            profit = max(arr[idx] + solve(idx+1 , arr,1, dp), // sell
                      solve(idx + 1, arr, 0, dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& Arr) {
        int n = Arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Base condition: When we have no stocks left, the profit is 0.
        dp[n][0] = dp[n][1] = 0;

        int profit;

        // Loop through the array in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) { // We can buy the stock
                    profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }

        // The maximum profit is stored in dp[0][0] after all calculations
        return dp[0][0];
    }
};