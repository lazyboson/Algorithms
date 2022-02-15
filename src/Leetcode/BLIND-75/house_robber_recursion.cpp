const int maxN = 101;
int dp[maxN];
class Solution {
public:
    int rob_count(vector<int>& nums, int n){
        if(n == 0)
            return nums[n];
        if(n < 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = max(nums[n] + rob_count(nums, n-2), nums[n-1]+rob_count(nums, n-3));
    }
    
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rob_count(nums, nums.size()-1);
    }
};
