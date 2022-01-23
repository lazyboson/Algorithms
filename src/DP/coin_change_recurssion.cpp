// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int coin_counter(int coins[], int size, int sum){
        //sum went below zero -- so current recursion tree is invalid -- return zero
        if(sum < 0)
            return 0;
    
        //this combination has given sum == 0, so count 1
        if(sum == 0)
            return 1;
        
        //if no further coins left and sum is still greater than zero, return zero
         if(size == -1 && sum > 0){
             return 0;
         }   
         
         
         return coin_counter(coins,size, sum-coins[size]) + coin_counter(coins, size-1, sum);
    }
    
    long long int count(int s[], int m, int n) {

        // code here.
        return coin_counter(s, m-1, n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
