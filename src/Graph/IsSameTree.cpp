
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        //if we have reached a level where both nodes are null
        if (p == nullptr && q == nullptr)
            return true;
        //if both nodes are not null -- then we would be comaring values of left and right subtree
        if (p != nullptr && q != nullptr) {
            return (p->val == q->val) && (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
        //two trees are not balanced 
        return false;
    }
};

int main(){
    return 0;
}