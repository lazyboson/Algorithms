#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vector<pair<int, int>> graph[100005];
int dis[100005];
bool processed[100005];
int parent[100005];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (size_t i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }
    for (size_t i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a] == true) {
            continue;
        }
        processed[a] = true;
        for (auto u : graph[a]) {
            int b = u.first, w = u.second;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                parent[b] = a;
                q.push({-dis[b], b});
            }
        }
    }

    stack<int> path;
    int dest = n;
    while (parent[dest] != 1) {
        path.push(dest);
        dest = parent[dest];
    }
    path.push(dest);
    path.push(1);
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    return 0;
}
