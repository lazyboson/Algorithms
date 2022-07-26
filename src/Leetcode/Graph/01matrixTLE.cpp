const int maxN = 1e4+1;
const int maxM = 1e4+1;

// -1, 0, 1, 0
//0, 1, 0, -1
vector<pair<int,int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int bfs(vector<vector<int>> &grid, int r, int c, int row, int col) {
        //resetting dis for each bfs call -> not optimal -> may be TLE
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> dis(row, vector<int>(col, 0));
        queue<pair<int,int>> q;
        q.push({r, c});
        visited[r][c] = true;
        auto isValidMove = [&](int locX, int locY, int row, int col){
            return locX >= 0 && locX <row && locY >= 0 && locY < col;
        };
        
        while(!q.empty()) {
            auto curr_loc = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int currX = curr_loc.first + directions[i].first;
                int currY = curr_loc.second + directions[i].second;
                if(!isValidMove(currX, currY, row, col) || visited[currX][currY])
                    continue;
                visited[currX][currY] = true;
                dis[currX][currY] = 1 + dis[curr_loc.first][curr_loc.second];
                if(grid[currX][currY] == 0)
                    return dis[currX][currY];
                q.push({currX, currY});
            }
        }
        return 0;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(mat[i][j] == 0)
                    res[i][j] = 0;
                else {
                    res[i][j] = bfs(mat, i, j, row, col);
                }
            }
        }
        return res;
    }
};
