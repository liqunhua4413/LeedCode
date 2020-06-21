/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路：dfs递归
根据题意总共有三种情况，最大路径在这三种情况里
（1）根节点的值 + 左子树的值
（2）根节点的值 + 右子树的值
（3）左子树的值 + 根节点的值 + 右子树的值 ： 这也是一条路径，左中右
节点最大贡献值maxMain：根节点的值 + max(leftGain, rightGain)。
内部一条路径最大和lmr：leftGain + root + rightGain。
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }
private:  
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == NULL) return 0;
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        //此节点node的最大贡献值
        int  nodeGain = node->val + max(leftGain, rightGain);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int lmr = node->val + leftGain + rightGain;

        // 更新答案，这时lmr这种情况3值一定大于情况1和情况2，所以下面直接maxSum和lmr比较就行。
        maxSum = max(maxSum, lmr);

        // 返回节点的最大贡献值
        return nodeGain;
    }
};
