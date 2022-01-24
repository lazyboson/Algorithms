class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*Idea - 1. maintain an array of length nums, and each index corresponding to nums will contains product from starting to that index.
        2. start traversing from the behind. and maintain a variable suffix_product that will hold product from last till current index.
        3. the value at any index say k ought to be. = prefix_products[k-1] * suffix_product[k+1...length]*/
       vector<int> ans(nums.size());
        int prefix = 1;
        for(int i=0; i<nums.size(); i++){
            prefix = prefix * nums[i];
            ans[i] = prefix;
        }
        int suffix_product = 1;
        for(int j=nums.size()-1; j > 0 ; j--) {
            if(j==nums.size()-1){
                ans[j] = ans[j-1];
                suffix_product *= nums[j];
            } else {
                ans[j] = ans[j-1] * suffix_product;
                suffix_product *= nums[j];
            }
        }
        
        ans[0] = suffix_product;
        return ans;
    }
};
