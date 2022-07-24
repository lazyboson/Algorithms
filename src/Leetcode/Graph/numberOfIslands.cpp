const int maxN = 301;
const int maxM = 301;
bool visited[maxN][maxM];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    void bfs(vector<vector<char>> &grid, int x, int y, int n, int m) {
        queue<pair<int,int>> q;
        q.push({x, y});
        visited[x][y] = true;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int ux = v.first + dx[i];
                int uy = v.second + dy[i];
                if(ux < 0 || ux >= n || uy < 0 || uy >= m) {
                    continue;
                }
                if(visited[ux][uy] || grid[ux][uy] != '1')
                    continue;
                visited[ux][uy] = true;
                q.push({ux, uy});
            } 
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        memset(visited, false, sizeof(visited));
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    bfs(grid, i, j, n, m);
                    ans++;
                } 
            }
        } 
        
        return ans;
    }
};
