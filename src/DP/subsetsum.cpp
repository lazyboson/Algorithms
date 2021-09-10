#include <iostream>

int main(){
    int size;
    std::cin >> size;
    int arr[size];
    for(int i=0;i <size;i++)
        std::cin >> arr[i];
    int requiredSum;
    std::cin >> requiredSum;
    bool dp[size+1][requiredSum+1];

    //initial condition for dp -- if sum = 0 then we can always have solution irrespective of array size
    //if arr = 0 and sum is non zero then we can't have solution --
    for(int i=0; i<requiredSum+1; i++){
        dp[0][i] = false;
    }
    for(int i=0; i<size+1; i++){
        dp[i][0] = true;
    }

    //other level solution
    for(int i=1; i<size+1; i++) {
        for(int j=1; j<requiredSum+1; j++) {
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    std::cout << dp[size][requiredSum] << std::endl;

}