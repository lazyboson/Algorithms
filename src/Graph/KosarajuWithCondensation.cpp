#include <iostream>
#include <vector>
#include <stack>

std::vector<int> adj[12];
std::vector<int> transpose_adj[12];


void dfs2(int start, std::vector<bool> &visited, std::vector<int> &components) {
    if (visited[start])
        return;
    visited[start] = true;
    components.push_back(start);
    for (auto const &u: transpose_adj[start]) {
        dfs2(u, visited, components);
    }
}

void dfs(int start, std::stack<int> &st, std::vector<bool> &visited) {
    if (visited[start])
        return;
    visited[start] = true;
    for (auto const &u: adj[start]) {
        dfs(u, st, visited);
    }
    st.push(start);
}

int main() {
    //building a directed graph -- using adjacency list data structure
    for (int i = 0; i < 5; ++i) {
        int src, dest;
        std::cin >> src >> dest;
        adj[src].push_back(dest);
    }

    //performing topological sort on the above graph
    std::vector<bool> visited(12, false);
    std::stack<int> st;
    //start visiting the available nodes using the dfs --
    for (int i = 1; i <= 5; ++i) {
        if (!visited[i])
            dfs(i, st, visited);
    }
    //taking transpose of the original graph
    for (int i = 0; i <= 5; ++i) {
        //reset the visited nodes for the dfs2 -- here
        visited[i] = false;
        for (auto const &u: adj[i]) {
            transpose_adj[u].push_back(i);
        }
    }
    //now start calling dfs2 from the topological sort containing array ---
    //In graph theory -- Strongly Connected Component means if you pick any node of graph's component then you can visit all the nodes in that component 
    //Algo -- Step 1 - First do Topological sort of the given graph..
    //    -- Step 2 - reverse the edges of directed graph or mathematically transpose the graph
    //    -- Step 3 -- perform the series of dfs on the topological-sort nodes ..
    std::cout << "Strongly Connected Components..." << "\n";
    std::vector<int> roots(5, 0);
    std::vector<int> root_nodes;
    std::vector<std::vector<int>> adj_scc(6);

    while (!st.empty()) {
        auto curr = st.top();
        st.pop();
        if (!visited[curr]) {
            std::vector<int> components;
            dfs2(curr, visited, components);
            int root = components.front();
            for (auto const &u: components) {
                roots[u] = root;
            }
            root_nodes.push_back(root);
        }
    }

    //condensing the scc into new adjacency of adj_scc
    for (int i = 1; i <= 5; ++i) {
        for (auto const &u: adj[i]) {
            int root_v = roots[i];
            int root_u = roots[u];
            if (root_u != root_v) {
                adj_scc[root_v].push_back(root_u);
            }
        }
    }

    for (int i = 1; i <= 5; i++) {
        std::cout << " the node ...." << i << " : ";
        for (auto const &u: adj_scc[i]) {
            std::cout << u << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

