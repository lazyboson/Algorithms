const int maxN = 1e3+5;
int dp[maxN][maxN];

class Solution {
public:
    int lcs(int pos1, int pos2, string &text1, string &text2){
        if(pos1 < 0 || pos2 < 0)
            return 0;
        if(dp[pos1][pos2] != -1)
            return dp[pos1][pos2];
        
        int ans = lcs(pos1-1, pos2, text1, text2);
        ans = max(ans, lcs(pos1, pos2-1, text1, text2));
        ans = max(ans, lcs(pos1-1, pos2-1, text1, text2) + (text1[pos1] == text2[pos2]));
        return dp[pos1][pos2] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return lcs(text1.size()-1, text2.size()-1, text1, text2);
    }
};
