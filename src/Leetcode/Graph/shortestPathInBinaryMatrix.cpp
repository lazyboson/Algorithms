const int maxN = 101;
const int maxM = 101;

int visited[maxN][maxM];
int dis[maxN][maxM];

vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

class Solution {
public:
    void bfs(vector<vector<int>> &grid, int r, int c, int row, int col) {
        queue<pair<int,int>> q;
        q.push({r, c});
        visited[r][c] = true;
        auto isValidMove = [&](int locX, int locY, int row, int col){
            return locX >= 0 && locX <row && locY >= 0 && locY < col;
        };
        
        while(!q.empty()) {
            auto curr_loc = q.front();
            q.pop();
            for(int i=0; i<8; i++) {
                int currX = curr_loc.first + directions[i].first;
                int currY = curr_loc.second + directions[i].second;
                if(!isValidMove(currX, currY, row, col) || grid[currX][currY] == 1 || visited[currX][currY])
                    continue;
                visited[currX][currY] = true;
                dis[currX][currY] = 1 + dis[curr_loc.first][curr_loc.second];
                q.push({currX, currY});
            }
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        memset(dis, 0, sizeof(dis));
        memset(visited, false, sizeof(visited));
        if(grid.size() == 0 || grid[0].size() == 0)
            return -1;
        int row = grid.size();
        int col = grid[0].size();
        bfs(grid, 0, 0, row, col);
        if(!visited[row-1][col-1] || grid[0][0] == 1)
            return -1;
        return dis[row-1][col-1] + 1;
    }
};
