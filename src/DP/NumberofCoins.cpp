#include<iostream>
#include<climits>

using namespace std;
class Solution{
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[M+1][V+1];
	    //dp--initialization
	    for(int i=0; i<M+1; i++)
	        dp[i][0] = 0;
	    for(int i=0; i<V+1; i++)
	        dp[0][i] = INT_MAX-1;
	   for(int i=1, j=1; j<M+1; j++) {
	       if(j%coins[i-1] == 0)
	           dp[i][j] = j/coins[i-1];
	       else
	           dp[i][j] = INT_MAX-1;
	   }
	   //main code -- 
	   for(int i=2; i<M+1; i++) {
	       for(int j=1; j<V+1; j++) {
	           if(coins[i-1] <= j)
	                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
	           else
	                dp[i][j] = dp[i-1][j];
	       }
	   }
       for(int i=1; i<M+1; i++){
           for(int j=1; j<V+1; j++){
               cout << dp[i][j] << " ";
           }
           cout << endl;
       }
	   if(dp[M][V] < 0)
	        return -1;
	   return dp[M][V];
	       
	} 	  
};

int main(){
    int sum = 30;
	int size = 3;
    // cin >> sum >> size;
    // int coins[size];
    // for(int i=0; i<size; i++)
    //     cin >> coins[size];
	int coins[3] = {25,10,5};
    Solution sln;
    int ans = sln.minCoins(coins, size, sum);
    cout << ans << endl;
    return 0;
}