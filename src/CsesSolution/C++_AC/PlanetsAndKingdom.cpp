/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author lazyboson
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <stack>
#include <map>

std::vector<int> adj[100001];
std::vector<int> trans_adj[100001];

class PlanetsAndKingdoms {
public:
    void dfs(int i, std::vector<bool> &visited, std::stack<int> &st) {
        if (visited[i])
            return;
        visited[i] = true;
        for (auto const &u: adj[i]) {
            dfs(u, visited, st);
        }
        st.push(i);
    }

    void dfs2(int curr, std::vector<bool> &visited, std::vector<int> &curr_set, int *cnt, std::map<int, int> &stars) {
        if (visited[curr])
            return;
        //memory optimization is possible  by just counting the objects based on value and ans 2-d vector is not needed
        visited[curr] = true;
        stars.insert(std::make_pair(curr, *cnt));
        curr_set.push_back(curr);
        for (auto const &u: trans_adj[curr]) {
            dfs2(u, visited, curr_set, cnt, stars);
        }
    }

    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;
        for (int i = 0; i < m; ++i) {
            int src, dest;
            in >> src >> dest;
            adj[src].push_back(dest);
        }

        std::vector<bool> visited(n, false);
        std::stack<int> st;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i, visited, st);
            }
        }

        std::vector<std::vector<int>> ans;

        for (int i = 1; i <= n; ++i) {
            visited[i] = false;
            for (auto const &u: adj[i]) {
                trans_adj[u].push_back(i);
            }
        }
        std::map<int, int> stars;
        int cnt = 0;
        while (!st.empty()) {
            auto curr = st.top();
            st.pop();
            std::vector<int> curr_set;
            if (!visited[curr]) {
                cnt++;
                dfs2(curr, visited, curr_set, &cnt, stars);
                ans.push_back(curr_set);
            }
        }

        //print the city --
        out << ans.size() << "\n";
        for (auto const &it: stars) {
            out << it.second << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    PlanetsAndKingdoms solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
