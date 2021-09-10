#include<iostream>
using namespace std;

int cntSubsetSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0; i<sum+1; i++)
        dp[0][i] = 0;
    for(int i=0; i<n+1; i++)
        dp[i][0] = 1;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int difference;
    cin >> difference;
    int actual_sum_needed;
    int sum =0;
    for(auto const &a: arr)
        sum += a;
    actual_sum_needed = (difference + sum)/2;
    int ans = cntSubsetSum(arr, n, actual_sum_needed);
    std::cout << ans <<endl;
    return 0;
}