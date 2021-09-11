#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstr (string S1, string S2, int n, int m) {
        // your code here
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++)
            dp[i][0] = 0;
        for(int i=0; i<m+1; i++)
            dp[0][i] = 0;
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        int max_val = 0;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(max_val < dp[i][j])
                    max_val = dp[i][j];
            }
        }
        return max_val; 
}

int main(){
    string text1, text2;
    cin >> text1 >>text2;
    int ans = longestCommonSubstr(text1, text2, text1.size(), text2.size());
    cout << ans <<endl;
    return 0;
}