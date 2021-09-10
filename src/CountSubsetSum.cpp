#include<iostream>

int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        int dp[n+1][sum+1];
        for(int i=0; i<sum+1; i++)
            dp[0][i] = 0;
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
}

int main(){
    int size, sum;
    std::cin >> size >> sum;
    int arr[size];
    for(int i=0; i<size; i++)
        std::cin >> arr[i];
    int ans = perfectSum(arr, size, sum);
    std::cout << ans <<std::endl;
}