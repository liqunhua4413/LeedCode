/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
思路：该方法一直报错，等周天统一调一下。
首先找到val相同的节点，找这个节点，只需遍历s的值是否有跟子树头节点值一样的即可。
然后比较后面的值是否相同，当到达NULL值时，还保持相同则是子树，否则不是。
*/
/*
bool DoesTree1HasTree2(struct TreeNode* t1, struct TreeNode* t2){ //比较两棵树后面的值是否相同。
    bool resLeft = false;
    bool resRight = false; //左右节点初始都设置为false即不同。
    //递归终止条件有3个。
    if(!t1 && !t2) return true; //t1和t2都为空，则t2是t1的子树。
    if(!t1 || !t2) return false; //上面已经判断t2和t1不同时为空，这时如果t1或t2为空，则t2不是t1的子树。
    if(t1->val != t2->val) return false; //t1和t2的值不一样，则t2不是t1的子树。
    //递归调用。
    resLeft = DoesTree1HasTree2(t1->left, t2->left);
    resRight = DoesTree1HasTree2(t1->right, t2->right);

    return (resLeft && resRight);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    bool res = false;
    if(s && t){ //保证两个二叉树非空，考虑鲁棒性。同时保证，如果下面递归isSubtree的时候，如果s已经为空，返回res的值即false。
        if(s->val == t->val) res = DoesTree1HasTree2(s, t); //当两个val相同时，判断树后面的值是否相同。
        //下面的思想很关键，就是当结果res为假，没有找到子树时，才允许继续找。一旦找到了就直接返回true了。
        if(!res) isSubtree(s->left, t);
        if(!res) isSubtree(s->right, t);        
    }
    return res;
}
*/

/*
先参考此人答案提交一波：
作者：xu-du-guang-yin-2
链接：https://leetcode-cn.com/problems/subtree-of-another-tree/solution/di-gui-suan-fa-jie-jue-zi-shu-wen-ti-by-xu-du-guan/
*/
bool compare (struct TreeNode* p1,struct TreeNode* p2)
{
    if(!p1&&!p2) return true;
    if(!p1||!p2) return false;
    if(p1->val!=p2->val) return false;
    return compare(p1->left,p2->left)&&compare(p1->right,p2->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(!s) return false;
    return compare(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
}

