const int maxN = 1001;
const int maxM = 3001;
bool visited[maxN];

class Solution {
public:
    void dfs(vector<vector<int>> &rooms, int v) {
        if(visited[v])
            return;
        visited[v] = true;
        for(auto const &u: rooms[v]) {
            dfs(rooms, u);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(visited, false, sizeof(visited));
        dfs(rooms, 0);
        for(int i=1; i<rooms.size(); i++) {
            if(!visited[i])
                return false;
        }
        return true;    
    }
};
