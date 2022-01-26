class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;
        for(auto const &t : text){
            if(t == 'b' || t == 'o' || t=='l' || t == 'a' || t == 'n'){
                cnt[t]++;
            }
        }
        if(cnt.size() != 5)
            return 0; 
        int l_cnt = cnt['l'];
        int o_cnt = cnt['o'];
        cnt['l'] = l_cnt/2;
        cnt['o'] = o_cnt/2;
        
        int res = INT_MAX;
        for(auto const &c : cnt){
            res = min(res, c.second);
        }
         if(res == INT_MAX) return 0;
        else
            return res;
    }
};
