#include <iostream>
#include <vector>
#include <stack>

std::vector<int> adj[12];
std::vector<int> transpose_adj[12];


void dfs2(int start, std::vector<bool> &visited){
    if(visited[start])
        return;
    visited[start] = true;
    std::cout << start << " ";
    for(auto const &u: transpose_adj[start]){
        dfs2(u, visited);
    }
}

void dfs(int start, std::stack<int> &st, std::vector<bool> &visited){
    if(visited[start])
        return;
    visited[start] = true;
    for(auto const &u: adj[start]){
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
    for (int i = 1; i <=5 ; ++i) {
        if (!visited[i])
            dfs(i, st, visited);
    }
   //taking transpose of the original graph
    for (int i = 0; i <= 5; ++i) {
        //reset the visited nodes for the dfs2 -- here
        visited[i] = false;
        for (auto const &u: adj[i]){
            transpose_adj[u].push_back(i);
        }
    }
    //now start calling dfs2 from the topological sort containing array ---
    //In graph theory -- Strongly Connected Components means if you pick a section of graph and choose a node then you
    //you can visit all node of that section by choosing any node in that section....
    //Algo -- Step 1 - First do Topological sort of the given graph..
    //    -- Step 2 - reverse the edges of directed graph or mathematically transpose the graph
    //    -- Step 3 -- perform the series of dfs on the toposort nodes ..
    std::cout << "Strongly Connected Components..." <<"\n";
    while (!st.empty()){
        auto curr = st.top();
        st.pop();
        if(!visited[curr]){
            dfs2(curr, visited);
            std::cout << "\n";
        }
    }
    return 0;
}

