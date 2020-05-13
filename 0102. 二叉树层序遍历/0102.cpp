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
 思路：
 建立一个辅助队列，用来存储每一层的节点数。
 建立一个辅助计数变量，用来计数这一层有多少节点，其值为队列的size。
 根据队列是否为空，来把每一层节点的值依次push_back到建立好的一维数组里。
 然后把每一层的一维数组push_back到二维数组里。
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> temp;
        int levelSize = 0; //每一层的节点数。
        queue<TreeNode *> que; //辅助队列

        que.push(root); //根节点入队。
        while(!que.empty()){
            levelSize = que.size(); //队列有多少个元素，每一层就有多少个节点
            for(int i = 0; i < levelSize; i++){ //每一层的levelSize节点出队，其子节点入队
                auto t = que.front(); //队列首元素
                temp.push_back(t->val); //每一层节点的值依次放到一维数组temp里。
                if(t->left){
                    que.push(t->left); //队列里这一层的左子节点，加入队列。
                } 
                if(t->right){
                    que.push(t->right); //队列里这一层的右子节点，加入队列。
                } 
                que.pop(); //队列这一层的节点出队
            }
            res.push_back(temp); //每一层的一维数组push_back到二维数组里
            temp.clear(); //清空temp
        }
        return res;
    }
};
