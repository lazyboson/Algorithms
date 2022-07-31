const int maxN = 1e5+1;
bool visited[maxN];

class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int v) {
        if(visited[v])
            return;
        visited[v] = true;
        for(auto const &u : adj[v]) {
            dfs(adj, u);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        memset(visited, false, sizeof(visited));  
        unordered_map<int, vector<int>> adj;
        int edges = 0;
        for(int i=0; i<connections.size(); i++) {
            adj[connections[i][0]].push_back({connections[i][1]});
            adj[connections[i][1]].push_back({connections[i][0]});
            edges++;
        }
       
        int cc = 0;
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                 dfs(adj, i);
                 cc++;
            }     
        }
        
        cout << cc << "\n";
        if(edges < n-1)
            return -1;
        int extraEdges = edges - ((n-1) - (cc-1));
        if(extraEdges >= cc-1) {
            return cc-1;
        } else {
            return -1;
        }
        
        
    }
};
