#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define GRAY 1
#define BLACK 2
#define WHITE 3

void dfs(vector<int> graph[], int start, int *visited, bool* has_cycle) {
    visited[start] = GRAY;
    for (auto const &e : graph[start]) {
        if (visited[e] == GRAY) {
            //you have found a cycle
            *has_cycle = true;
            return;
        }
        if (visited[e] == WHITE) {
            dfs(graph, e, visited, has_cycle);
        }
    }
    visited[start] = BLACK;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> graph[12];
    int visited[12];
    //constructing the graph here -- it is essentially a directed acyclic graph
   
    graph[1].push_back(10);
    graph[1].push_back(11);
    graph[2].push_back(7);
    graph[5].push_back(6);
    //graph[1].push_back(2);
    graph[7].push_back(5);
    graph[3].push_back(4);
    graph[11].push_back(3);
    graph[7].push_back(5);
    graph[5].push_back(2);
    bool has_cycle = false;
    //making all the white color
    for (size_t i = 1; i < 12; i++) {
        visited[i] = WHITE;
    }
    for (size_t i = 1; i < 12; i++) {
        if (visited[i] == WHITE && !has_cycle)
            dfs(graph, i, visited, &has_cycle);
    }
    if (has_cycle)
        cout << "Graph has a cycle " << endl;
    else
        cout << "Graph doesn't contain a cycle" << endl;
    return 0;
}
