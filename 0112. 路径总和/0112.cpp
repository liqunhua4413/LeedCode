/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) { //特殊情况。
            return false;
        }
        return hasPathSumHelper(root, sum);
    }
private:
    bool hasPathSumHelper(TreeNode* root, int sum){
        if (root->left == nullptr && root->right == nullptr) { //递归终止条件。
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

