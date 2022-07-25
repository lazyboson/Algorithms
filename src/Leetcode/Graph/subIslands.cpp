const int maxN = 501;
const int maxM = 501;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[maxN][maxM];

class Solution {
public:
    bool bfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y, int n, int m) {
       queue<pair<int,int>> q;
        q.push({x, y});
        visited[x][y] = true;
        bool isSubIsland = true;
        while(!q.empty()) {
            auto v = q.front();
            if(grid1[v.first][v.second] != 1)
                isSubIsland = false;
            q.pop();
            for(int i=0; i<4; i++) {
                int ux = v.first + dx[i];
                int uy = v.second + dy[i];
                if(ux < 0 || ux >= n || uy < 0 || uy >= m) 
                    continue;
                if(visited[ux][uy] || grid2[ux][uy] != 1)
                    continue;
                visited[ux][uy] = true;
                q.push({ux, uy});
            } 
        }
        return isSubIsland;
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        memset(visited, false, sizeof(visited));
        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j< m; j++) {
                if(!visited[i][j] && grid2[i][j] == 1) {
                    bool isSubIsland = bfs(grid1, grid2, i, j, n, m);
                    if(isSubIsland)
                        count++;
                }
            }
        }
        return count;
        
    }
};
