const int maxN = 101;
int dp[maxN];
bool isLast;

class Solution {
public:
    int rob_count(vector<int>& nums, int n){
        if(n == 0)
            return nums[n];
        if(n < 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = max(nums[n] + rob_count(nums, n-2), nums[n-1] + rob_count(nums, n-3));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        memset(dp, -1, sizeof(dp));
        int a = rob_count(nums, nums.size()-2);
        memset(dp, -1, sizeof(dp));
        nums.erase(nums.begin()+0);
        int b = rob_count(nums, nums.size()-1);
            return max(a,b);
    }
};
