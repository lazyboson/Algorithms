#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {
    }
};

class Solution {
  public:
    bool check_symmetry(TreeNode *tree1, TreeNode *tree2) {
        if (tree1 == nullptr && tree2 == nullptr)
            return true;
        if (tree1 && tree2 && tree1->val == tree2->val) {
            return check_symmetry(tree1->left, tree2->right) && check_symmetry(tree1->right, tree2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        check_symmetry(root, root);
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //you can built the tree
    return 0;
}
