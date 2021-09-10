#include<iostream>
#include <vector>
#include <climits>

using namespace std;
class Solution{
  public:
    vector<int> possibleSum(int arr[], int n, int sum){
        vector<int> data;
        bool dp[n+1][sum+1];
        for(int i= 0; i<sum+1; i++)
            dp[0][i] = false;
        for(int i=0; i<n+1; i++)
            dp[i][0] = true;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int range = 0;
        if(sum%2 == 0)
            range = (sum+1)/2;
        else
            range = sum/2;
        for(int i=0; i<=range; i++){
            if(dp[n][i])
                data.push_back(i);
        }
        return data;
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++)
	        sum += arr[i];
	   vector<int> data = possibleSum(arr,n,sum);
	   int min_val = INT_MAX;
	   for(int i=0; i<data.size(); i++){
	       min_val = min(min_val, sum-(2*data[i])); 
	   }
	   return min_val;
	} 

};

int main(){
    Solution sln;
    int size;
    cin >> size;
    int arr[size];
    for(int i=0; i< size; i++)
        cin >> arr[i];
    int ans = sln.minDifference(arr, size);
    std::cout << ans <<endl;
}