/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author lazyboson
 */

//Problem -- https://open.kattis.com/problems/countingstars
#include <bits/stdc++.h>

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class CountingStars {
public:
    void dfs(int x, int y, int rows, int cols, vector<vector<char>> &adj, set<pair<int, int>> &visited) {
        auto is_valid_coordinate = [&](int xCor, int yCor) {
            return (xCor >= 0 && xCor < rows && yCor >= 0 && yCor < cols);
        };

        if (visited.find({x, y}) != visited.end())
            return;
        visited.insert({x, y});
        for (int i = 0; i < 4; ++i) {
            int ux = x + dx[i];
            int uy = y + dy[i];
            if (!is_valid_coordinate(ux, uy) || adj[ux][uy] == '#')
                continue;
            dfs(ux, uy, rows, cols, adj, visited);
        }
    }

    void solve(std::istream &in, std::ostream &out) {
        int tc = 1;
        int rows, cols;
        while (in >> rows && in >> cols) {
            vector<vector<char>> adj(rows, vector<char>(cols));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    char input;
                    in >> input;
                    adj[i][j] = input;
                }
            }
            set<pair<int, int>> visited;
            int cc = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (visited.find({i, j}) == visited.end() && adj[i][j] != '#') {
                        cc++;
                        dfs(i, j, rows, cols, adj, visited);
                    }
                }
            }
            out << "Case " << tc << ": " << cc << "\n";
            tc++;
        }
    }
};

int main() {
	CountingStars solver;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}