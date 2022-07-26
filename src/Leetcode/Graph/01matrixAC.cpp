const int maxN = 1e4+1;
const int maxM = 1e4+1;
bool visited[maxN][maxM];
// -1, 0, 1, 0
//0, 1, 0, -1
vector<pair<int,int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int bfs(queue<pair<int,int>> q, vector<vector<int>> &grid, int row, int col) {
        
        auto isValidMove = [&](int locX, int locY, int row, int col){
            return locX >= 0 && locX <row && locY >= 0 && locY < col;
        };
        while(!q.empty()) {
            auto curr_loc = q.front();
            q.pop();
            visited[curr_loc.first][curr_loc.second] = true;
            for(int i=0; i<4; i++) {
                int currX = curr_loc.first + directions[i].first;
                int currY = curr_loc.second + directions[i].second;
                if(!isValidMove(currX, currY, row, col) || visited[currX][currY])
                    continue;
                visited[currX][currY] = true;
                grid[currX][currY] = 1 + grid[curr_loc.first][curr_loc.second];
                q.push({currX, currY});
            }
        }
        return 0;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>> q;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                     if(mat[i][j] == 0){
                         q.push({i, j});
                         visited[i][j] = true;
                     }
                }
            }
        bfs(q, mat, row, col);
        return mat;
    }
};
