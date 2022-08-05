class Solution {
public:
    void dfs(vector<int> &arr, int start, vector<bool> &visited, bool *hasReached) { 
        auto isCorrectMove = [&](int index) {
            return index >= 0 && index < arr.size();
        };     
        if(!isCorrectMove(start) || visited[start])
            return;   
        if(arr[start] == 0){
            *hasReached = true;
            return;
        }
        visited[start] = true;
        dfs(arr, start+arr[start], visited, hasReached);
        dfs(arr, start-arr[start], visited, hasReached);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> visited(len+1, false);
        bool hasReached = false; 
        dfs(arr, start,visited, &hasReached);
        if(hasReached)
            return true;
        return false;
        
    }
};
