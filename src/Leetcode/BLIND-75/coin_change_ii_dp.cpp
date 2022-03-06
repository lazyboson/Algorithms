const int maxPos = 305;
const int maxN = 5005;
int dp[maxPos][maxN];

class Solution {
public:
    int coin_combinations(vector<int> &coins, int pos, int amount){
        if(amount ==0)
            return 1;
        if(pos < 0)
            return 0;
        if(dp[pos][amount] != -1)
            return dp[pos][amount];
        if(pos < 0)
            return 0;
        if(amount-coins[pos] >= 0)
            return dp[pos][amount] = coin_combinations(coins, pos, amount-coins[pos]) + coin_combinations(coins, pos-1, amount);
        else
            return dp[pos][amount] = coin_combinations(coins, pos-1, amount);        
    }
    
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return coin_combinations(coins,coins.size()-1, amount);
    }
};
