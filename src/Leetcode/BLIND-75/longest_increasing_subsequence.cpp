const int maxN = 1e4+5;
int dp[maxN];

class Solution {
public:
    
    int lis(int pos, vector<int> &nums){
       if(dp[pos] != -1)
           return dp[pos];
        int ans = 1;
        for(int i=0; i<pos; i++){
            if(nums[i] < nums[pos])
                ans = max(ans, lis(i, nums)+1);
        }
        return dp[pos] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, lis(i, nums));
        }
        return ans;
    }
};
