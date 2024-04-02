class Solution {
public:
    int solve(int idx1, int idx2, string s, string t,  vector<vector<int>> &dp){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2]){
            return dp[idx1][idx2] = solve(idx1 - 1, idx2 - 1, s,t, dp) + solve(idx1 - 1, idx2, s, t, dp);
        }
        return dp[idx1][idx2] = solve(idx1 - 1, idx2, s, t, dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(s.size()-1, t.size()-1, s, t, dp);
    }
};