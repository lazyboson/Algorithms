class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left_pos = 0;
        int right_pos = numbers.size() -1;
        while(left_pos < right_pos){
            int current_sum = numbers[left_pos] + numbers[right_pos]; 
            if(current_sum == target){
                return {left_pos+1, right_pos+1};
            } else if (current_sum > target){
                right_pos -= 1;
            } else {
                left_pos +=1;
            }
        }
        return {};
    }
};
