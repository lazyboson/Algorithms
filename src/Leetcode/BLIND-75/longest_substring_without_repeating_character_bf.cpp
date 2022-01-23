class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return 1;
        int ans =0;
        for(int i=0; i<s.size()-1; i++){
            set<char> sub_str;
            sub_str.insert(s[i]);
            for(int j=i+1; j<s.size(); j++){
                pair<set<char>::iterator, bool> check_insert = sub_str.insert(s[j]);
                if(!check_insert.second)
                    break;  
            }
            if(ans < sub_str.size())
                ans = sub_str.size();
        }
        return ans;
    }
};
