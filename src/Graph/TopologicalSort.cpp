#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int visited[12];
int states[12];
vector<int> graph[12];
stack<int> ans;

void dfs(int start) {
    if (visited[start] == true)
        return;
    visited[start] = true;

    for (auto const &e : graph[start]) {
        dfs(e);
    }
    // start pushing in the stack once u r done with visiting all the neighbour of a node
    ans.push(start);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // initally all the nodes are wHITE
    int edge_cnt;
    cin >> edge_cnt;
    // constructing the directed acyclic graph
    for (size_t i = 0; i < edge_cnt; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    // for seven node graph starting at 4 - ---
    // 4 1
    // 4 5
    // 5 3
    // 5 2
    // 1 2
    // 2 3
    // 3 6
    //---Expected output -- 4,5,1,2,3,6
    dfs(4);
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}
