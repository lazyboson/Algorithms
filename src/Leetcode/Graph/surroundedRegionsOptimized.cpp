class Solution {
public:
    void dfs(vector<vector<char>> &grid, int r, int c, int row, int col){
        auto isValid = [&](int r, int c) {
            return (r  >= 0 && r < row && c >= 0 && c < col);
        };
        if(!isValid(r,c) || grid[r][c] == 'X' || grid[r][c] == 'T')
            return;
        grid[r][c] = 'T';
        dfs(grid, r+1, c, row, col);
        dfs(grid, r-1, c, row, col);
        dfs(grid, r, c+1, row, col);
        dfs(grid, r, c-1, row, col);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        auto isBorderShell= [&](int x, int y) {
            return x==0 || x==rows-1 || y == 0 || y==cols-1;
        }; 
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j< cols; j++) {
                if(board[i][j] == 'O' && isBorderShell(i, j)) {
                    dfs(board, i, j, rows, cols);
                }
            }
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
        
    }
};
