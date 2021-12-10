class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == NULL)
            return ans;
        map<int,int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            auto current = n.first;
            auto curr_level = n.second;
            m[curr_level] = current->data;
            if(current->left != NULL){
                q.push({root->left, curr_level-1});
            }
            if(current->right != NULL) {
                q.push({root->right, curr_level+1});
            }
        }
        
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};