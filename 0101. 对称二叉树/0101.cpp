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
 思路1：递归
 p 指针和 q指针一开始都指向这棵树的根，随后 p右移时，q左移，p左移时，q右移。每次检查当前 p和 q节点的值是否相等，如果相等再判断左右子树是否对称。
 */
 /*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
private:
    bool check(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        return (root1->val == root2->val) && check(root1->left, root2->right) && check(root1->right, root2->left);
    }
};
*/
/*
思路2：迭代
*/
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            // 每次出队两个节点 node1 和 node2
            u = q.front(); q.pop();
            v = q.front(); q.pop();

            // 首先判断节点空的情况；然后比较 node1 与 node2 这两个节点的值是否相等
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            // 再将 node1 的左节点与 node2 的右节点一起入队（以便两节点一起出队，进行比较
            q.push(u->left); 
            q.push(v->right);

             // 再将 node1 的右节点与 node2 的左节点一起入队（以便两节点一起出队，进行比较）
            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
