class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int targetNode = graph.size() - 1;
        vector<vector<int>> paths;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()) {
            auto nodeList = q.front();
            q.pop();
            int currLast = nodeList[nodeList.size()-1];
            if(targetNode == currLast) {
                paths.push_back(nodeList);
            } else {
                auto neighbors = graph[currLast];
                for(auto const &neighbor: neighbors) {
                    vector<int> newList = nodeList;
                    newList.push_back(neighbor);
                    q.push(newList);
                }
            }
        }
        return paths;
    }
};
