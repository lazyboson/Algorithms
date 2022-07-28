vector<pair<int,int>> directions = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    //performing multi level bfs 
     int bfs(queue<pair<int,int>> q, vector<vector<int>> &grid, int row, int col, int *fresh){
        auto isValidMove = [&](int locX, int locY, int row, int col){
            return locX >= 0 && locX <row && locY >= 0 && locY < col;
        };
         
       int time = 0;
        while(!q.empty()) {
            int sz = q.size();
            time++;
            for(int it = 0; it < sz; it++) {
                auto curr_loc = q.front();
                q.pop();
                for(int i=0; i<4; i++) {
                    int currX = curr_loc.first + directions[i].first;
                    int currY = curr_loc.second + directions[i].second;
                    if(!isValidMove(currX, currY, row, col) || grid[currX][currY] != 1)
                        continue;
                    grid[currX][currY] = 2;
                    q.push({currX, currY});
                    (*fresh)--;
                    if(*fresh==0)
                        return time;
                }
            }
          
        }
        return time;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size() ;
        int cols = grid[0].size();
        int fresh = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j< cols; j++) {
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
        if(fresh == 0)
            return 0;
        int time = bfs(q, grid, rows, cols, &fresh);
        
        if(fresh == 0)
            return  time;
        else
            return -1;
    }
};
