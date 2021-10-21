#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int m = cost.size();
        int dp[m + 1];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < m; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[m - 1], dp[m - 2]);
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
