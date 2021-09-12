#include<bits/stdc++.h>
using namespace std;

int minDeletions(string A, int n) { 

    //complete the function here 
        string B = A;
        reverse(A.begin(), A.end());
        int m = B.size();
        int dp[m+1][m+1];
        for(int i=0;i<m+1; i++)
        dp[0][i] = 0;
        for(int i=0; i<m+1; i++)
            dp[i][0] = 0;
        for(int i=1; i<m+1; i++){
            for(int j=1; j<m+1; j++){
                if(B[i-1] == A[j-1]){
                 dp[i][j] = dp[i-1][j-1]+1;
                }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return n-dp[m][m];
} 

int main(){
    string a;
    cin >> a;
    int ans = minDeletions(a, a.size());
    cout << ans << endl;

}