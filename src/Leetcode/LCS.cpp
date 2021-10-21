#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class Solution {
  public:
    int dp[1001][1001];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int lcs(int x, int y, string s1, string s2) {
        // your code here
        int dp[x + 1][y + 1];
        //initialization of bottom up
        for (int i = 0; i < x + 1; i++)
            dp[i][0] = 0;
        for (int i = 0; i < y + 1; i++)
            dp[0][i] = 0;
        for (int i = 1; i < x + 1; i++) {
            for (int j = 1; j < y + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x][y];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        return ans = lcs(text1.size(), text2.size(), text1, text2);
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //build DS here
    return 0;
}
