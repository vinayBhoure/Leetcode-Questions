class Solution {
public:
    int solve(vector<vector<int>> &grid, vector<vector<int>>&dp, int row, int col){
        if (row == 0 && col == 0)
        return grid[0][0];

    if (row < 0 || col < 0)
        return 1e9;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = grid[row][col] + solve(grid, dp, row - 1, col);
    int left = grid[row][col] + solve(grid, dp, row, col - 1);

    return dp[row][col] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans = solve(grid, dp, n-1, m-1);
        return ans;
    }
};