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
 
std::vector<int> adj[100001];
std::vector<int> trans_adj[100001];
 
class FlightRoutesCheck {
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
 
    void dfs2(int curr, std::vector<bool> &visited, std::vector<int> &curr_set) {
        if (visited[curr])
            return;
        visited[curr] = true;
        curr_set.push_back(curr);
        for (auto const &u: trans_adj[curr]) {
            dfs2(u, visited, curr_set);
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
        std::stack<int> st;
        std::vector<bool> visited(n, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                dfs(i, visited, st);
        }
 
        std::vector<std::vector<int>> ans;
 
        for (int i = 1; i <= n; ++i) {
            visited[i] = false;
            for (auto const &u: adj[i]) {
                trans_adj[u].push_back(i);
            }
        }
 
        while (!st.empty()) {
            auto curr = st.top();
            st.pop();
            std::vector<int> curr_set;
            if (!visited[curr]) {
                dfs2(curr, visited, curr_set);
                ans.push_back(curr_set);
            }
        }
        if (ans.size() == 1 || ans.empty())
            out << "YES" << "\n";
        else {
            out << "NO" << "\n";
            //printing the specific cities that can't be travelled in current routes ---
            for (int i = 0; i < (int) ans[0].size(); ++i) {
                int src = ans[0][i];
                //out << src << "\n";
                for (int j = 0; j < (int) ans[1].size(); ++j) {
                    int dest = ans[1][j];
                    //out << dest <<"\n";
                    if (adj[src].empty()) {
                        out << dest << " " << src << "\n";
                        return;
                    } else {
                        bool has_found = false;
                        for (auto const &u: adj[src]) {
                            if (u == dest) {
                                has_found = true;
                            }
                        }
                        if (!has_found) {
                            out << dest << " " << src << "\n";
                            return;
                        }
                    }
                }
            }
            for (int i = 0; i < (int) ans[1].size(); ++i) {
                int src = ans[1][i];
                //out << src << "\n";
                for (int j = 0; j < (int) ans[0].size(); ++j) {
                    int dest = ans[0][j];
                    //out << dest <<"\n";
                    if (adj[src].empty()) {
                        out << src << " " << dest << "\n";
                        return;
                    } else {
                        bool has_found = false;
                        for (auto const &u: adj[src]) {
                            if (u == dest) {
                                has_found = true;
                            }
                        }
                        if (!has_found) {
                            out << src << " " << dest << "\n";
                            return;
                        }
                    }
                }
            }
        }
    }
};
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    FlightRoutesCheck solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
