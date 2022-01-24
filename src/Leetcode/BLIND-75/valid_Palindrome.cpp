class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        for(int i=0; i<s.size(); i++){
            if('a'<= tolower(s[i]) && tolower(s[i]) <= 'z'){
                newS += tolower(s[i]);
            }
            if(s[i] >= '0' && s[i] <= '9'){
                newS += s[i];
            }
        }
        cout << newS <<endl;
        for(int i=0, j=newS.size()-1 ; i<j; ++i, --j){
            if(newS[i] != newS[j]){
                return false;
            }
            
        }
        return true;
    }
};
