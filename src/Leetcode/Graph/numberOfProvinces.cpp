const int maxN = 201;
bool visited[maxN];
class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int v) {
        if(visited[v])
            return;
        visited[v] = true;
        for(int j=0; j<isConnected[v].size(); j++ ) {
            if(isConnected[v][j] == 1 && !visited[j]) {
                dfs(isConnected, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(visited, false, sizeof(visited));
        int cc = 0; 
        for(int i=0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                cc++;
                dfs(isConnected, i);
            }
        }
        return cc;
    }
};
