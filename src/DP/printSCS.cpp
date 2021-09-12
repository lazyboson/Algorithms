#include<bits/stdc++.h>
using namespace std;

string lcs(string text1, string text2, int m, int n){
    int dp[m+1][n+1];
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = 1+ min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    std::string result;
    int i = m, j=n;
    while(i>0 && j>0) {
         if(text1[i-1] == text2[j-1]){
                result.push_back(text1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                    result.push_back(text2[j-1]);
                    j--;
            } 
            else {
                    result.push_back(text1[i-1]);
                    i--;
            }
    }
    
    while(i > 0){
        result.push_back(text1[i-1]);
        i--;
    }
    while(j > 0){
        result.push_back(text2[j-1]);
        j--;
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