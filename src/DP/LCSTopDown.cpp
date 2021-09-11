#include<bits/stdc++.h>
using namespace std;

int lcs(string text1, string text2, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<m+1; i++)
        dp[0][i] = 0;
    for(int i=0; i<n+1; i++)
        dp[i][0] = 0;
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    string text1, text2;
    cin >> text1 >>text2;
    int ans = lcs(text1, text2, text1.size(), text2.size());
    cout << ans <<endl;
    return 0;
}