#include <iostream>

int main(){
    int size;
    std::cin >> size;
    int arr[size];
    for(int i=0; i<size; i++)
        std::cin >> arr[i];
    int isSumEven = 0;
    for(auto const &a:arr)
        isSumEven += a;
    if(isSumEven %2 != 0){
        std::cout << "False "<<std::endl;
    }
    else{
        int sumToCheck = isSumEven/2;
        bool dp[size+1][sumToCheck+1];
        for(int i=0; i<sumToCheck+1; i++){
             dp[0][i] = false;
        }
        for(int i=0; i<size+1; i++){
            dp[i][0] = true;
        }

        for(int i=1; i<size+1; i++){
            for(int j=1; j<sumToCheck+1; j++){
                if(arr[i-1] <= j ){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[size][sumToCheck])
            std::cout <<"True" <<std::endl;
        else
             std::cout <<"False" << std::endl;
     }
    return 0;
}