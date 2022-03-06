const int maxN = 1e5+5;
int dp[maxN];

class Solution {
public:
    int coin_count(vector<int> &coins, int amount){ 
        if(amount == 0) 
            return 0;
        if(dp[amount] != -1)
            return dp[amount];
        
        int res = INT_MAX;
        
        for(auto coin: coins){
            if(amount-coin >=0)
                res = min(res+0LL , 1LL+coin_count(coins, amount-coin));   
        }
        return dp[amount] = res;
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = coin_count(coins, amount);
         return ans==INT_MAX?-1:ans;
       
    }
};
