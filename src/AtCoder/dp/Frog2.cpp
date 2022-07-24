/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author lazyboson
 */


#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;
int dp[maxN];

class BFrog2 {
public:
    int jump_cost(int curr_pos, int leap_possible, vector<int> &costs) {
        if (curr_pos == 0)
            return 0;
        if (dp[curr_pos] != -1)
            return dp[curr_pos];
        int cost = INT_MAX;
        for (int i = 1; i <= leap_possible; i++) {
            if (curr_pos - i >= 0) {
                cost = min(cost,
                           abs(costs[curr_pos - i] - costs[curr_pos]) + jump_cost(curr_pos - i, leap_possible, costs));
            }
        }
        return dp[curr_pos] = cost;
    }

    void solve(std::istream &in, std::ostream &out) {
        memset(dp, -1, sizeof(dp));
        int n, k;
        in >> n >> k;
        vector<int> costs(n);
        for (int i = 0; i < n; ++i) {
            in >> costs[i];
        }

        out << jump_cost(n - 1, k, costs);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    BFrog2 solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}