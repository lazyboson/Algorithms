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
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        if (left_depth > right_depth) {
            left_depth += 1;
            return left_depth;
        } else {
            right_depth += 1;
            return right_depth;
        }
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
