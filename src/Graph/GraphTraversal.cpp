#include <bits/stdc++.h>

void dfs(const std::vector<int> graph[], bool *visited, int start) {
    if (visited[start] == true)
        return;
    visited[start] = true;
    for (const auto &d : graph[start]) {
        dfs(graph, visited, d);
    }
}

void bfs(const std::vector<int> graph[], bool *visited, int *distance, std::queue<int> _q, int start) {
    visited[start] = true;
    distance[start] = 0;
    _q.push(start);
    while (!_q.empty()) {
        const int s = _q.front();
        _q.pop();
        //process node start
        for (const auto &u : graph[s]) {
            if (visited[u] == true) {
                continue;
            }
            visited[u] = true;
            distance[u] = distance[s] + 1;
            _q.push(u);
        }
    }
}

int connected_component(std::vector<int> graph[]) {
    int connectedCnt = 0;
    // ReSharper disable once CppTooWideScope
    bool visited[12];

    //specific for my case it can be generalized
    for (unsigned i = 0; i < 12; i++) {
        if (!graph[i].empty()) {
            if (visited[i] != true) {
                connectedCnt++;
                dfs(graph, visited, i);
            }
        }
    }
    return connectedCnt;
}

int main() {
    //constructing the graph here -- it is essentially a directed acyclic graph
    std::vector<int> graph[12];
    bool visited[12];
    graph[1].push_back(10);
    graph[1].push_back(11);
    graph[2].push_back(7);
    graph[5].push_back(6);
    //graph[1].push_back(2);
    graph[7].push_back(5);
    graph[3].push_back(4);

    dfs(graph, visited, 1);
    bool bfs_visited[12];
    std::queue<int> q;
    int distance[12] = {};
    bfs(graph, bfs_visited, distance, q, 1);

    for (int i = 1; i < 12; i++) {
        std::cout << "Distance from Node " << i << " from the start 1 " << distance[i] << std::endl;
    }

    const int connectCnt = connected_component(graph);
    std::cout << "Number of the connected Component in the graph is : " << connectCnt << std::endl;

    return 0;
}
