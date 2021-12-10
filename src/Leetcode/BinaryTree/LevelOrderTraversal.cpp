class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto node = q.front();
                q.pop();
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                
                if(node->right != nullptr)
                    q.push(node->right);
                
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};