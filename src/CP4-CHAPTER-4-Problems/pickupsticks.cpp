/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author lazyboson
 */

//Problem -- https://open.kattis.com/problems/pickupsticks
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6 + 5;
vector<int> adj[maxN];
vector<int> inbound;

class PickUpSticks {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;
        inbound.assign(n, 0);
        for (int i = 0; i < m; ++i) {
            int src, dest;
            in >> src >> dest, --src, --dest;
            adj[src].push_back(dest);
        }

        for (int i = 0; i < n; ++i) {
            for (auto const &e: adj[i]) {
                inbound[e]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inbound[i] == 0)
                q.push(i);
        }

        int index = 0;
        vector<int> order(n);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            order[index++] = u;
            for (auto const &e: adj[u]) {
                inbound[e]--;
                if (inbound[e] == 0)
                    q.push(e);
            }
        }
        if (index != n) {
            out << "IMPOSSIBLE" << "\n";
        } else {
            for (auto &d: order)
                out << ++d << "\n";
        }
    }
};

int main() {
	PickUpSticks solver;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
