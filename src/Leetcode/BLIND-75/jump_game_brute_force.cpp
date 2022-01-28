class Solution {
public:
    void possibleJump(vector<int> &nums, int curr, int n, bool *isPossible){
        if (curr > n)
            return;
        if(curr == n-1){
            *isPossible = true;
            return;
        }
        for(int i=1; i <= nums[curr]; i++){
            if(*isPossible == true)
                break;
            possibleJump(nums, curr+i, n, isPossible);
        }
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        bool isPossible = false;
        possibleJump(nums, 0, nums.size(), &isPossible);
        return isPossible;
    }
};
