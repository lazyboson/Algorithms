vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool isValidMove (int x, int y, int rows, int cols) {
            return x >= 0 && x < rows && y >= 0 && y< cols;
    }
        
    void dfs(vector<vector<int>> &grid, int x, int y, int rows, int cols, set<pair<int,int>> &visited) {     
        if(!isValidMove(x,y, rows, cols) || visited.find({x,y}) != visited.end() || !grid[x][y]) {
            return;
        } 
        
        visited.insert({x, y});
        for(auto const &d: directions) {
            dfs(grid, x + d.first, y + d.second, rows, cols, visited);
        }
    }
    
    int bfs(vector<vector<int>> &grid, int rows, int cols, queue<pair<int,int>> q, set<pair<int,int>> &visited) {
        int ans = 0; 
        while(!q.empty()) {
            auto sz = q.size() ;
            for(int i=0; i<sz; i++) {
                auto coordinate = q.front();
                q.pop();
                for(int j=0; j<4; j++) {
                    int cor_x = coordinate.first + directions[j].first;
                    int cor_y = coordinate.second + directions[j].second;
                    if(!isValidMove(cor_x, cor_y, rows, cols) || visited.find({cor_x, cor_y}) != visited.end())
                         continue; 
                     visited.insert({cor_x, cor_y});
                     q.push({cor_x, cor_y});
                     if(grid[cor_x][cor_y])
                         return ans;
                } 
            } 
            ans++;
        }
        return ans;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        set<pair<int,int>> visited;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, rows, cols, visited);
                    goto jump; 
                }
            }
        }
        jump: 
            queue<pair<int,int>> q;
            for(auto const &v: visited) {
                q.push(v);
            }
            int ans = bfs(grid, rows, cols, q, visited);
        
             return ans; 
    }
};
