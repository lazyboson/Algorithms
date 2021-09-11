#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        if(x==0 || y==0)
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        if(s1[x-1] == s2[y-1]){
            dp[x][y] =  1+lcs(x-1, y-1, s1, s2);
            return dp[x][y];
        }
        else{
            dp[x][y] = max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1,s2));
            return dp[x][y];
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        return ans = lcs(text1.size(), text2.size(), text1, text2);
    }
};

int main(){
    string text1, text2;
    cin >> text1 >> text2;
    Solution sln;

    int ans = sln.longestCommonSubsequence(text1, text2);
    std::cout << ans <<std::endl;
}

