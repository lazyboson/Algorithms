class Solution {
public:
    bool isPalindrome(const string &s){
        for(int i=0, j=s.size()-1; i<j; ++i, --j){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string ans;
        /*Genrate all substrings  and check if it palindrome and keep max*/
        for(int i=0; i<s.size(); i++){
            for(int j=1; j<=s.size()-i; j++){
                string current = s.substr(i,j);
                if(isPalindrome(current)){
                    if(current.size() > ans.size())
                        ans = current;
                }
            }
        }
        return ans;
    }
};
