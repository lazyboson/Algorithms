#include<bits/stdc++.h>
#include <queue>
#include <vector>

int main()
{
    std::vector<std::pair<int, int>> edges[12];
    //building the graph here
    for (int i = 1; i <= 12; i++) {
        int to, from, weight;
        std::cin >> to >> from >> weight;
        edges[to].push_back(std::make_pair(from, weight));
        edges[from].push_back(std::make_pair(to, weight));
    }
    int distance[12];
    
    bool processed[12];
    //setting value of distance to INFINITY 
    for (int i = 1; i < 12; i++)
        distance[i] = INT_MAX;
    std::queue<std::pair<int, int>> q;
    distance[1] = 0;
    q.push({ 0, 1 });
    while (!q.empty()) {
        int a = q.top();
        q.pop();
        if (processed[a] == true)
            continue;
        processed[a] = true;
        for (const auto& e : edges[a]) {
            int b = e.first;
            int w = e.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({ -distance[b], b });
            }
        }
    }
}