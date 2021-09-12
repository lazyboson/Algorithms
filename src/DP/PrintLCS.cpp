#include<bits/stdc++.h>
using namespace std;

string lcs(string text1, string text2, int m, int n){
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
    std::string result;
    int i = m, j=n;
    while(i>0 && j>0){
         if(text1[i-1] == text2[j-1]){
                result.push_back(text1[i-1]);
                i=i-1;
                j=j-1;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])
                    i--;
                else
                    j--;
            }
    }
    reverse(result.begin(), result.end());

    return result;
}
int main(){
    string text1, text2;
    cin >> text1 >>text2;
    string ans = lcs(text1, text2, text1.size(), text2.size());
    cout << ans <<endl;
    return 0;
}