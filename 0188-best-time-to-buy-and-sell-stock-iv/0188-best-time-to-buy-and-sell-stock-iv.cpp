class Solution {
public:
    int solve(int idx, int t, int k, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(idx == n || t == 2*k) return 0;
        
        if(dp[idx][t] != -1) return dp[idx][t];
        
        if(t%2 == 0){
            int buy = -prices[idx] + solve(idx+1, t+1, k, n, prices, dp);
            int not_buy = 0 + solve(idx+1, t, k, n, prices, dp);
            return dp[idx][t] = max(buy, not_buy);
        }
        
        int sell = prices[idx] + solve(idx+1, t+1, k, n, prices, dp);
        int not_sell = 0 + solve(idx+1, t, k, n, prices, dp);
        return dp[idx][t] = max(sell, not_sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int idx=n-1; idx>=0; idx--){
            for(int t=2*k-1; t>=0; t--){
                if(t%2 == 0){
                    int buy = -prices[idx] + dp[idx+1][t+1];
                    int not_buy = 0 + dp[idx+1][t];
                    dp[idx][t] = max(buy, not_buy);
                }
                else{
                    int sell = prices[idx] + dp[idx+1][t+1];
                    int not_sell = 0 + dp[idx+1][t];
                    dp[idx][t] = max(sell, not_sell);
                }
            }
        }
            
        return dp[0][0];
    }
};