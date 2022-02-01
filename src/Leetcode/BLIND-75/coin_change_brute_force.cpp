int res = INT_MAX;
class Solution {
public:
    int coin_count(vector<int> &coins, int size, int amount){
        if(amount == 0) 
            return 0;
        int res = INT_MAX;
        for(int i=0; i<=size; i++){
            if(coins[i] <= amount){
                //unbounded knapsack -- since coins supply is unlimited.
                int curr = coin_count(coins, size, amount-coins[i]);
                if(curr < INT_MAX && curr + 1 < res){
                    res = curr + 1;
                }
            }
        }
        return res;
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = coin_count(coins, coins.size()-1, amount);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
