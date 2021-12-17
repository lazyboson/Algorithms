class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> side(n, -1);
        bool is_bipartite = true;
        queue<int> q;
        for(int st=0; st<n; st++){
            if(side[st] == -1){
                q.push(st);
                side[st] = 0;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(auto const &u: graph[v]){
                        if(side[u] == -1){
                            side[u] = side[v]^1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[v] != side[u];
                        }
                    }
                }
            }
        }
        return is_bipartite;
    }
};
