#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class Solution {

  public:
    int dp[46];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
