class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int level = 0;
        queue<TreeNode*> q;
	// level order traversal -- set root node as zeroth level, and place this in queue and subsiquently left and right nodes, if they are present in the node. 
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                     q.push(node->right);
             }
            
            level++;
        }
        return level;
    }
};
