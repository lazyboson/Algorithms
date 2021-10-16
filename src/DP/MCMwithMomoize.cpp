#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

static int dp[1001][1001];

int cost_function(int arr[], int start_index, int end_index) {
    if (start_index == end_index)
        return 0;
    if (dp[start_index][end_index] != -1)
        return dp[start_index][end_index];
    int temp;
    int res = INT_MAX;
    for (size_t i = start_index; i < end_index; i++) {
        temp = cost_function(arr, start_index, i) + cost_function(arr, i + 1, end_index) +
               arr[start_index - 1] * arr[i] * arr[end_index];
        res = min(res, temp);
    }
    dp[start_index][end_index] = res;
    return dp[start_index][end_index];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // intializing the dp to -1
    memset(dp, -1, sizeof(dp));
    int matrix_cnt;
    std::cin >> matrix_cnt;
    int arr[matrix_cnt];
    for (size_t i = 0; i < matrix_cnt; i++) {
        std::cin >> arr[i];
    }
    int res = cost_function(arr, 1, matrix_cnt - 1);
    std::cout << res << std::endl;
    return 0;
}
