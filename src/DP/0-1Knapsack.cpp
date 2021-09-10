#include<iostream>
#include<vector>
#include<memory>
#include<utility>
#include <cstring>

using namespace std;
int dp[102][1002];

int Knapsack(int w[], int v[], int W, int size){
    if(W == 0  || size == 0)
        return 0;
    if(dp[size][W] != -1)
        return dp[size][W];
    if(w[size-1] <= W){
        dp[size][W] =  max(v[size-1]+Knapsack(w,v,W-w[size-1],size-1), Knapsack(w,v,W,size-1));
        return dp[size][W];
    }
    if(w[size-1] > W){
         dp[size][W] =  Knapsack(w,v,W,size-1);
         return dp[size][W];
    }   
}
int main(){
    memset(dp, -1, sizeof(dp));

    int size;
    cin >> size;
    int w[size], v[size];
    for(int i=0; i<size; i++){
        cin >> w[i];
    }
    for(int i=0; i<size; i++){
        cin >> v[i];
    }
    int W;
    cin >> W;
    int ans = Knapsack(w,v,W,size);
    cout << ans <<endl;
    return 0;
}