class Solution {
public:
    int solve(int i, int amount, vector<int>& coins,
              vector<vector<int>>& dp) {

        int n = coins.size();

        if (amount == 0)
            return 1;

        if (amount < 0)
            return 0;

        if (i >= n)
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = solve(i, amount - coins[i], coins, dp);

        int not_take = solve(i + 1, amount, coins, dp);

        return dp[i][amount] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(0, amount, coins, dp);
    }
};