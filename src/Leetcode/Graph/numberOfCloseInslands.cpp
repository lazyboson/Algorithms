const int maxN = 101;
const int maxM = 101;
bool visited[maxN][maxM];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    bool bfs(vector<vector<int>>& grid, int x, int y, int n, int m){
        queue<pair<int,int>> q;
        q.push({x, y});
        bool isIsolatedIsland = true;
        while(!q.empty()) {
            auto v = q.front();
            if(v.first == 0 || v.first == n-1 || v.second == 0 || v.second == m-1)
                isIsolatedIsland = false;
            q.pop();
            for(int i=0; i<4; i++) {
                int ux = v.first + dx[i];
                int uy = v.second + dy[i];
                if(ux < 0 || ux>= n || uy < 0 || uy >= m)
                    continue;
                if(visited[ux][uy] || grid[ux][uy] == 1)
                    continue;
               //zero's on the edge of the grid -- so it is no longer a closed island 
                visited[ux][uy] = true;
                q.push({ux, uy});
            }
        }
        return isIsolatedIsland;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
         int n= grid.size();
        int m = grid[0].size();
        memset(visited, false, sizeof(visited));
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == 0) {
                    bool curr = bfs(grid, i, j, n, m);
                    if(curr) 
                        ans++;
                } 
            }
        } 
        return ans;
       
    }
};
