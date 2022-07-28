class Solution {
public:
    void dfs(vector<vector<char>> &grid, int r, int c, set<pair<int,int>> &visited, int row, int col, bool *isEdgeReached) {
        auto isValid = [&](int r, int c) {
            return (r  >= 0 && r < row && c >= 0 && c < col);
        };
        if(visited.find({r,c}) != visited.end() || !isValid(r,c) || grid[r][c] == 'X')
            return;
        if(r==0 || r==row-1 || c==0 || c==col-1)
            *isEdgeReached = true;
        visited.insert({r,c});
        dfs(grid, r+1, c, visited, row, col, isEdgeReached);
        dfs(grid, r-1, c, visited, row, col, isEdgeReached);
        dfs(grid, r, c+1, visited, row, col, isEdgeReached);
        dfs(grid, r, c-1, visited, row, col, isEdgeReached);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j< cols; j++) {
                if(board[i][j] == 'O') {
                    set<pair<int,int>> visited;
                    bool isEdgeReached = false;
                    dfs(board, i, j, visited, rows, cols, &isEdgeReached);
                    if(!isEdgeReached) {
                        for(auto const &v: visited) {
                            board[v.first][v.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
