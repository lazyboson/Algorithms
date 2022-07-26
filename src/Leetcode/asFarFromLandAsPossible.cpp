const int maxN = 101;
const int maxM = 101;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dis[maxN][maxM];
int res[maxN][maxM];

class Solution {
public:
    void bfs(vector<vector<int>> &grid, int x, int y, int n, int m) {
        queue<pair<int,int>> q;
        q.push({x, y});
        bool visited[n][m];
        memset(visited, false, sizeof(visited));
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            visited[v.first][v.second] = true;
            for(int i=0; i<4; i++) {
                int ux = v.first + dx[i] ;
                int uy = v.second + dy[i];
                if(ux < 0 || ux >= n || uy < 0 || uy >= m || grid[ux][uy] == 1)
                    continue;
                if(visited[ux][uy])
                    continue;
                q.push({ux, uy});
                dis[ux][uy] = 1 + dis[v.first][v.second];
                res[ux][uy] = res[ux][uy] == 0? dis[ux][uy] : min(res[ux][uy], dis[ux][uy]); 
                visited[ux][uy] = true;
            }
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        memset(dis, 0, sizeof(dis));
        memset(res, 0, sizeof(res));
        
        int stepTaken = INT_MAX;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                     bfs(grid, i, j, n, m);
                } 
            }
        }
        
        int maxVal = INT_MIN;
     
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                maxVal = max(maxVal, res[i][j]);
            }
        }
        return maxVal == 0 ? -1 : maxVal;
    }
};
