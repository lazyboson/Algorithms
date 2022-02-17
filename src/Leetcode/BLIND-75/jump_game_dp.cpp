const int maxN = 1e4+5;
int dp[maxN];
class Solution {
public:
    bool dfs(int index, int size, vector<int> &nums) {
        if(size <= index)
            return true;
        if(dp[index] != -1)
            return dp[index];
        for(int i=1; i<=nums[index]; i++){
            auto res = dfs(index+i, size, nums);
            if(res){
                dp[index] = true;
                return dp[index];
            }
        }
        return dp[index] = false;
    } 
    
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        if(nums.size() == 1)
            return true;
        return dfs(0, nums.size()-1, nums);
    }
};
