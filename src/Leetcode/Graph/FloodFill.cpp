class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        int n = image.size();
        int m = image[0].size();
        bool visited[n+1][m+1];
        memset(visited, false, sizeof(visited));
        
        int originalColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int ux = v.first + dx[i];
                int uy = v.second + dy[i];
                // out of range
                if(ux < 0 || ux >=n || uy < 0 || uy >= m)
                    continue;
                //already visited
                if(visited[ux][uy])
                    continue;
                if(image[ux][uy] != originalColor)
                    continue;
                
                image[ux][uy] = color;
                visited[ux][uy] = true;
                q.push({ux, uy});
            }
        }
        image[sr][sc] = color;
        return image;
    }
};
