class Solution {
public:
    void dfs(TreeNode *root, int level, vector<int> &ans){
        if(root == nullptr)
            return;
        if(level == ans.size())
            ans.push_back(root->val);
        dfs(root->right, level+1, ans);
        dfs(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};