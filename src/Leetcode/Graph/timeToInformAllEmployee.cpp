class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &adj, int headId, vector<int> &informTime) {
        int ans = 0;
       queue<pair<int, int>> q;
        q.push({headId, informTime[headId]});
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            ans = max(ans, v.second);
            for(auto  &u: adj[v.first]) {
                q.push({u, informTime[u] + v.second});
            }
        }
        
        return ans;
}
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<manager.size(); i++) {
            if(manager[i] != -1)
            adj[manager[i]].push_back(i);
        }
        int ans = bfs(adj, headID, informTime);
        return ans;
    }
};
