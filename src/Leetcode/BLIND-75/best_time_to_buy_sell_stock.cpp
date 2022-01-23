class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int res = 0;
        /*Idea - we will start from second element and keep track of possible min_val and max price would be trcked using current-min_val*/
        for(int i= 1; i<prices.size(); i++){
            res = max(res, prices[i]-min_val);
            min_val = min(min_val, prices[i]);
        }
        return res;
    }
};
