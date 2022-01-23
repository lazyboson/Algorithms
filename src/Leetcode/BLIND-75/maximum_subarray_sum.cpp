class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int currMax = 0;
        /*use - Kadane's Algorithm - Idea is following - if we have taken an subarray and found it's negative, then it this subarray is included in further subarray's it will be going to reduce the value of union of subarrays, So, we make the currMax = 0, once we got negative and maxVal holds the maximum from that subarray*/
        for(int i=0; i<nums.size(); i++){
            currMax += nums[i];
            if(currMax > maxVal)
                maxVal = currMax;
            if(currMax < 0)
                currMax = 0;
        }
        return maxVal;
    }
};
