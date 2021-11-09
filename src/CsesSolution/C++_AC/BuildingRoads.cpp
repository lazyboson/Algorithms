#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)
 
vector<int> adj[200005];
bool visited[200005];
 
class Solution {
public:
    
    void dfs(int start, bool hasFound, int &lastNode) {
        if (visited[start])
            return;
        visited[start] = true;
        for (auto u : adj[start]) {
            if (u != start && !hasFound) {
                lastNode = u;
                hasFound = true;
            }
            dfs(u, hasFound, lastNode);
        }
    }
 
    void solve(std::istream& in, std::ostream& out) {
        int n, m;
        in >> n >> m;
        //constructing the graph
        for (int i = 1; i <= m; i++) {
            int src, dest;
            in >> src >> dest;
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        
        int preserveState = 0;
        int ans = 0;
        vector<vector<int>> possibleRoads;
 
        for (int i = 1; i < n+1 ; i++) {
            if (visited[i] != true) {
                if (i != 1) {
                    possibleRoads.push_back({ preserveState, i });
                }
                int current = i;
                ans++;
                dfs(i, false, current);
                preserveState = current;
            }
        }
        out << ans - 1 << endl;
        for (auto a : possibleRoads) {
            out << a[0] << " " << a[1] << endl;
        }
    }
};
 
void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
 
 
#include <fstream>
#include <iostream>
 
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
 
    istream& in = cin;
 
 
    ostream& out = cout;
 
    solve(in, out);
    return 0;
}
 