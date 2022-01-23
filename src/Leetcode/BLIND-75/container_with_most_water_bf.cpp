class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i=0; i< n-1; i++){
            for(int j= i+1; j < n; j++){
               int feasible_height = min(height[j], height[i]);
               res = max(res, (j-i)*feasible_height);
            }
        }
        return res;
    }
};
