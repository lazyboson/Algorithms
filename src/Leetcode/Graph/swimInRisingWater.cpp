class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        priority_queue<pair<int, pair<int,int>>,  vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        set<pair<int, int>> visited;
        pq.push({grid[0][0], {0, 0}});
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited.insert({0, 0});
        auto isValidMove = [&](int x, int y) {
            return x>=0 && x<rows && y>=0 && y<cols;
        };
        
        while(!pq.empty()) {
           auto v = pq.top();
           pq.pop();
            
            if(v.second.first == rows-1 && v.second.second == cols-1)
                return v.first;
           for(auto const &d : directions) {
               auto ux = v.second.first + d.first;
               auto uy = v.second.second+d.second;
              if(!isValidMove(ux,uy)  || visited.find({ux, uy}) != visited.end())  
                  continue;
               visited.insert({ux, uy});
               pq.push({max(v.first, grid[ux][uy]),{ux, uy}});
               
           }
        }
        return -1;
    }
};
