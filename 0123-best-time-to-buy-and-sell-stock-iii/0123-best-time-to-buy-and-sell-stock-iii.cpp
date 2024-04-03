class Solution {
public:
    int solve(int idx, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(idx == n) return 0;

        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        if(buy == 1){
            int buy_profit = -prices[idx] + solve(idx+1, 0, cap, prices, n, dp);
            int not_buy_profit = 0 + solve(idx+1, 1, cap, prices, n, dp);
            return dp[idx][buy][cap] = max(buy_profit, not_buy_profit);
        }

        int sell_profit = prices[idx] + solve(idx+1, 1, cap-1, prices, n, dp);
        int not_sell_profit = solve(idx+1, 0, cap, prices, n, dp);
        return dp[idx][buy][cap] = max(sell_profit, not_sell_profit);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        
        for(int idx=n-1; idx>=0; idx--){
            for(int buy =0; buy <=1; buy++){
                for(int cap = 1; cap<=2; cap++ ){
                    
                    if(buy == 1){
                        int buy_profit = -prices[idx] + dp[idx+1][0][cap];
                        int not_buy_profit = 0 + dp[idx+1][1][cap];
                        dp[idx][buy][cap] = max(buy_profit, not_buy_profit);
                    }
                     else{
                        int sell_profit = prices[idx] + dp[idx+1][1][cap-1];
                        int not_sell_profit = dp[idx+1][0][cap];
                        dp[idx][buy][cap] = max(sell_profit, not_sell_profit);
                     }
                }
            }
        }
       
        return dp[0][1][2];
    }
};