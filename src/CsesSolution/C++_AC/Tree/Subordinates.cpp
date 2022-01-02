#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5+5;
int n, count[maxN];
vector<int> adj[maxN];

void dfs(int u, int p){
    count[u] = 1;
    for(auto const &v:adj[u]){
        dfs(v, u);
        count[u]+=count[v];
    }
}

class Subordinates {
public:
	void solve(std::istream& in, std::ostream& out) {
        in >> n;
        for (int i = 1; i <n; ++i) {
           int p;
           in >> p, --p;
           adj[p].push_back(i);
        }
        dfs(0, -1);

        for (int i = 0; i <n ; ++i) {
           out << count[i]-1 << " ";
        }

	}
};
