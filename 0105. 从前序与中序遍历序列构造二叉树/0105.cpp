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
 思路：递归
 参考别人思路，感觉还是挺清晰的。
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() <= 0 && inorder.size() <= 0 && preorder.size() != inorder.size()) return NULL;
        return myBuildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode * myBuildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight){
        //递归终止条件
        if(pLeft > pRight || iLeft > iRight) return NULL;
        //重建根节点，前序遍历中的第一个节点就是根节点
        TreeNode*  treeNode = new TreeNode(preorder[pLeft]);
        //得到左子树的长度
        int index = 0; 
        while(inorder[iLeft + index] != preorder[pLeft]) index++;
        //重建左子树
        treeNode->left = myBuildTree(preorder, pLeft + 1, pLeft + index, inorder, iLeft, iLeft + index - 1);
        treeNode->right = myBuildTree(preorder, pLeft + index + 1, pRight, inorder, iLeft + index + 1, iRight);
        return treeNode;
    }
};
