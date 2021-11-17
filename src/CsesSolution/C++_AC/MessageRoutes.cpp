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
#include <queue>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)
#define MAXIMUM 1000000
vector<pair<int, int>> adj[200005];
bool visited[200005];
int dis[200005];
int predecessors[200005];
 
class Solution {
public:
    void printPath(int start, int end, std::ostream& out) {
        vector<int> paths;
        for (int i = end; i != start; i = predecessors[i]) {
            paths.push_back(i);
        }
        paths.push_back(start);
        for (int i = paths.size() - 1; i >= 0; i--) {
            out << paths[i] << " ";
        }
        out << endl;
    }
 
    void dijkstras(int start, int end) {
        dis[start] = 0;
        priority_queue<pair<int, int>> queue;
        queue.push({ 0, start });
        while (!queue.empty()) {
            int a = queue.top().second; 
            queue.pop();
            if (visited[a] == true) {
                continue;
            }
            visited[a] = true;
            for (auto u : adj[a]) {
                int b = u.first, w = u.second;
                if (dis[a] + w < dis[b]) {
                    dis[b] = dis[a] + w;
                    queue.push({-dis[b], b });
                    predecessors[b] = a;
                }
            }
        }
    }
 
    void solve(std::istream& in, std::ostream& out) {
        int n, m;
        in >> n >> m;
        for (int i = 0; i < m; i++) {
          int src, dest;
          in >> src >> dest;
          adj[src].push_back({dest, 1});
          adj[dest].push_back({src, 1});
        }
        for (int i = 0; i <= n; i++)
            dis[i] = MAXIMUM;
        for (int i = 0; i <= n + 1; i++)
          predecessors[i] = -1;
        dijkstras(1, n);
        if (dis[n] == MAXIMUM)
            out << "IMPOSSIBLE" << endl;
        else {
            out << dis[n]+1 << endl;
            printPath(1, n, out);
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
 