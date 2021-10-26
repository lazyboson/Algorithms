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
    int height(TreeNode *current) {
        if (current == nullptr)
            return 0;
        return 1 + max(height(current->left), height(current->right));
    }

    bool isBalanced(TreeNode *root) {
        int left_height;
        int right_height;

        if (root == nullptr)
            return true;
        left_height = height(root->left);
        right_height = height(root->right);

        if (abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //implement your tree here --
    return 0;
}
