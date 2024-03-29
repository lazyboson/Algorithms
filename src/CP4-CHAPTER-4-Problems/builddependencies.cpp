/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author lazyboson
 */
//Problem - https://open.kattis.com/problems/builddeps
#include <bits/stdc++.h>

#define UNVISITED 0
#define VISITED 1

using namespace std;

const int maxN = 1e5 + 5;
vector<int> adj[maxN];
vector<int> dfs_num(maxN);
stack<int> ts;

class BuildDependencies {
public:
    string get_actual_string(string &s) {
        string ss;
        for (int i = 0; i < s.size() - 1; ++i) {
            ss += s[i];
        }
        return ss;
    }

    void dfs(int source) {
        if (dfs_num[source] == VISITED)
            return;
        dfs_num[source] = VISITED;

        for (auto const &u: adj[source]) {
            dfs(u);
        }
        ts.push(source);
    }


    void solve(std::istream &in, std::ostream &out) {
        unordered_map<string, int> mp;
        unordered_map<int, string> ans_mp;
        int n;
        in >> n;
        string changed_node;
        int index = 0;
        for (int i = 0; i <= n + 1; ++i) {
            string ss;
            getline(in, ss);
            char split_char = ' ';
            std::istringstream split(ss);
            std::vector<std::string> tokens;
            for (std::string each; std::getline(split, each, split_char); tokens.push_back(each));
            if (tokens.size() == 1) {
                if (tokens[0][tokens[0].size() - 1] == ':') {
                    auto actual_string = get_actual_string(tokens[0]);
                    if (mp.find(actual_string) == mp.end()) {
                        mp[actual_string] = index;
                        ans_mp[index] = actual_string;
                        index++;
                    }
                } else {
                    changed_node = tokens[0];
                }
            } else {
                string first;
                for (int j = 0; j < tokens.size(); ++j) {
                    string curr;
                    if (j == 0) {
                        curr = get_actual_string(tokens[j]);
                        first = curr;
                    } else {
                        curr = tokens[j];
                    }
                    if (mp.find(curr) == mp.end()) {
                        mp[curr] = index;
                        ans_mp[index] = curr;
                        index++;
                    }
                    if (j > 0) {
                        adj[mp[curr]].push_back(mp[first]);
                    }
                }
            }
        }
        dfs_num.assign(n, UNVISITED);
        dfs(mp[changed_node]);
        while (!ts.empty()) {
            auto a = ts.top();
            ts.pop();
            out << ans_mp[a] << "\n";
        }
    }
};

int main() {
    BuildDependencies solver;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
