			
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            int mid = (left+right)/2; 
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] >= nums[left]) { // if current chunk of array between left and mid is monotonically increasing and target is this section then assign right = mid-1
                if(target >= nums[left] && target <= nums[mid]) {
                    right = mid -1;
                } else {
                    left = mid +1;
                }
            }
            else { //if left-mid chunk is monotonically increasing then mid-right would be monotonically increasing, because of property of array
                if(target >= nums[mid] && target <= nums[right]) {
                    left = mid +1;
                }  else {
                    right = mid -1;
                } 
            }
        }
       return -1; 
    }
};
