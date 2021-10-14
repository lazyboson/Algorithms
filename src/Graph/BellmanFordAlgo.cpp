#include <bits/stdc++.h>
#include <vector>

int main()
{
    // constructing a graph of edge list data structure
    std::vector<std::tuple<int, int, int>> edges;
    edges.push_back({ 1, 2, 5 });
    edges.push_back({ 2, 1, 5 });
    edges.push_back({ 2, 6, 2 });
    edges.push_back({ 6, 2, 2 });
    edges.push_back({ 6, 4, 2 });
    edges.push_back({ 4, 6, 2 });
    edges.push_back({ 1, 4, 7 });
    edges.push_back({ 4, 1, 7 });
    edges.push_back({ 4, 3, 1 });
    edges.push_back({ 3, 4, 1 });
    edges.push_back({ 1, 3, 3 });
    edges.push_back({ 3, 1, 3 });
    edges.push_back({ 4, 2, 3 });
    edges.push_back({ 2, 4, 3 });

    int distance[10];
    for (int i = 1; i < 10; i++)
        distance[i] = INT_MAX;
    // node from where search to start
    distance[1] = 0;

    for (int i = 1; i <= 6; i++) {
        for (const auto &e : edges) {
            int a, b, w;
            std::tie(a, b, w) = e;
            distance[b] = std::min(distance[b], distance[a] + w);
        }
    }

    // non-ambigious val represents distance of each node from the 1
    for (const auto &d : distance)
        std::cout << d << std::endl;
}