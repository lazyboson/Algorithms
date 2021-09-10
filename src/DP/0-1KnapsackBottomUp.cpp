#include <iostream>

int main() {
    int size;
    std::cin >> size;
    int w[size], v[size];
    for(int i=0; i<size; i++){
        std::cin >> w[i];
    }
    for(int i=0; i<size; i++){
        std::cin >> v[i];
    }
    int W;
    std::cin >> W;
    int dp[size+1][W+1];
    //initialize the dp--with base condition of knapsack--.
    //settin up first row and first columns to zero because if n==0 then return 0 and if W==0 return 0
    for(int i=0; i<W+1; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<size+1; i++){
        dp[i][0] = 0;
    }
    //solution for other parts--

    for(int i=1; i<size+1; i++){
        for(int j=1; j<W+1; j++){
            if(w[i-1] <= j){
                dp[i][j]= std::max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }   
        }
    }
    std::cout << dp[size][W] <<std::endl;
}