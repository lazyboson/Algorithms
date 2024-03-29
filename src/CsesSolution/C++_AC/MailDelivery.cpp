/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author lazyboson
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>

const int maxN = 1e5;
const int maxM = 2e5;

int eu[maxM], ev[maxM];
std::vector<int> adj[maxN], ans;
bool used[maxM];

class MailDelivery {
public:
    void dfs(int u = 0) {
        while (adj[u].size()) {
            int e = adj[u].back();
            adj[u].pop_back();
            if (used[e])
                continue;
            used[e] = 1;
            dfs(eu[e] ^ ev[e] ^ u);
            ans.push_back(u);
        }
    }

    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;
        for (int i = 0; i < m; ++i) {
            in >> eu[i] >> ev[i], --eu[i], --ev[i];
            adj[eu[i]].push_back(i);
            adj[ev[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() & 1) {
                out << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        ans.push_back(0);
        dfs();
        if (ans.size() ^ (m + 1)) {
            out << "IMPOSSIBLE" << "\n";
        } else {
            for (auto const &a: ans) {
                out << a + 1 << " ";
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    MailDelivery solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
