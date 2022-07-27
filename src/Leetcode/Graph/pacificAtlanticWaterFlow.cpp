class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, set<pair<int,int>> &visited, int row, int col, int lastHeight) {
        auto isValid = [&](int r, int c) {
            return (r  >= 0 && r < row && c >= 0 && c < col);
        };
        if(visited.find({r,c}) != visited.end() || !isValid(r,c) || (grid[r][c] < lastHeight))
            return;
        visited.insert({r,c});
        dfs(grid, r+1, c, visited, row, col, grid[r][c]);
        dfs(grid, r-1, c, visited, row, col, grid[r][c]);
        dfs(grid, r, c+1, visited, row, col, grid[r][c]);
        dfs(grid, r, c-1, visited, row, col, grid[r][c]);
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       if(heights.size() == 0 || heights[0].size() == 0)
           return {};
        int row = heights.size();
        int col = heights[0].size();
        
        set<pair<int,int>> pac, atl;
        vector<vector<int>> ans;
        
        for(int i=0; i<col; i++) {
            dfs(heights, 0, i, pac, row, col, heights[0][i]);
            dfs(heights, row-1, i, atl, row, col, heights[row-1][i]);
        }
        
        
        for(int j=0; j<row; j++) {
            dfs(heights, j, 0, pac, row, col, heights[j][0]);
            dfs(heights, j, col-1, atl, row, col, heights[j][col-1]);
        }    
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++) {
                if((pac.find({i,j}) != pac.end()) && (atl.find({i,j}) != atl.end())){
                   ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
