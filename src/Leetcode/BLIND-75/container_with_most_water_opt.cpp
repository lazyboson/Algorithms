class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int left_pos = 0;
        int right_pos = n-1;
       /* solving with two pointer technique -- we are maintaing left and right positions and since height is main contrains - which pointer has lower height, will be changed to next possible*/ 
        while(left_pos < right_pos){
            if(height[right_pos] >= height[left_pos]){
                res = max(res, (right_pos - left_pos)*height[left_pos]);
                left_pos++;
            } else {
                res = max(res, (right_pos - left_pos)*height[right_pos]);
                right_pos--;
            }
        } 
        return res;
    }
};
