vector<pair<int,int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
class Solution {
public:
    int bfs(vector<vector<char>> &maze, int x, int y, int rows, int cols, vector<int> &start) {
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({x, y});
        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        auto isValidMove = [&](int x, int y) {
               return x>=0 && x<rows && y >= 0 && y < cols;
        }; 
        auto isOuterShell = [&](int x, int y) {
            return (x == 0 || x == rows-1 || y == 0 || y == cols-1);
        };
        
        while(!q.empty()) {
                pair<int, int>  coordinates = q.front();
                q.pop();
                visited.insert({x, y}); 
                for(auto const &d: directions) {
                    int newX = coordinates.first + d.first;
                    int newY = coordinates.second + d.second;
                    if(!isValidMove(newX, newY) ||  visited.find({newX, newY}) != visited.end() || maze[newX][newY] == '+')
                        continue;
                    visited.insert({newX, newY});
                    q.push({newX, newY});
                    dist[newX][newY] = 1 + dist[coordinates.first][coordinates.second];
                    if(isOuterShell(newX, newY) && !(make_pair(newX, newY) == make_pair(start[0], start[1]))) {
                        return dist[newX][newY];
                    }
                }
        }
        
        return 0;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        
        auto ans = bfs(maze, entrance[0], entrance[1], rows, cols, entrance);
        return ans == 0 ? -1 : ans;
    }
};
