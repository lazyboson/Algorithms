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
    TreeNode *invertTree(TreeNode *root) {
        //if null received -- no action required
        if (root == nullptr)
            return root;
        invertTree(root->left);
        invertTree(root->right);

        //swaping the references here
        TreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //built your tree here and call for invertTree
    return 0;
}
