#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;


class Solution {
public:
    int minDistance(string str1, string str2) {
        // Your code goes here
	    int m=str1.size();
	    int n= str2.size();
	    int dp[m+1][n+1];
	    for(int i=0; i<m+1; i++){
	        dp[i][0]=0;
	    }
	     for(int i=0; i<n+1; i++){
	        dp[0][i]=0;
	    }
	    
	    for(int i=1; i<m+1; i++){
	        for(int j=1; j<n+1; j++){
	            if(str1[i-1] == str2[j-1])
	                dp[i][j] = 1+dp[i-1][j-1];
	            else 
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    int ans = (m-dp[m][n]) + (n-dp[m][n]);
	    return ans;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
