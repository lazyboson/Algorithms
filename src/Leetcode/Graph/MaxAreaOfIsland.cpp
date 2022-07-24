const int maxN = 51;
const int maxM = 51;
bool visited[maxN][maxM];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int x, int y, int n, int m){
        queue<pair<int,int>> q;
        int count = 0;
        q.push({x, y});
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            count++;
            for(int i=0; i<4; i++) {
                int ux = v.first + dx[i];
                int uy = v.second + dy[i];
                if(ux < 0 || ux>= n || uy < 0 || uy >= m)
                    continue;
                if(visited[ux][uy] || grid[ux][uy] == 0)
                    continue;
                visited[ux][uy] = true;
                q.push({ux, uy});
            }
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n= grid.size();
        int m = grid[0].size();
       memset(visited, false, sizeof(visited));
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    int curr = bfs(grid, i, j, n, m);
                    curr = curr == 1? curr : --curr;
                    ans = max(ans, curr);
                } 
            }
        } 
        return ans;
       
    }
};
