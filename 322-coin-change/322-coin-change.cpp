class Solution {
private:
    int dp[15][20001];
    int solve(vector<int>& coins, int amount, int idx, int cur = 0) {
        if (cur > amount)
            return 1e5;
        if(dp[idx][cur])
            return dp[idx][cur];
        if (cur == amount)
            return 0;
        int option1 = solve(coins, amount, idx, cur + coins[idx]) + 1;
        int option2 = 0;
        if (idx - 1 < 0)
            option2 = 1e5;
        else
            option2 = solve(coins, amount, idx - 1, cur);

        return dp[idx][cur] = min(option1, option2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int idx = coins.size() - 1;
        for(int i = coins.size() -1; i >= 0; i--)
            if(coins[i] <= amount){
                idx = i; break;
            }
        int ans = solve(coins, amount, idx);
        if (ans >= 1e5)
            return -1;
        return ans;
    }
};