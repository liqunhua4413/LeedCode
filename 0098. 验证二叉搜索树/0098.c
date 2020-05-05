/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /*
 思路一：
 今天生病，暂且抄一个。
 */
/*
// 深搜函数，target为根结点的值，Position为0说明在遍历左子树，为1说明在遍历右子树
bool DFS(struct TreeNode* root, int target, int Position){
    if (root == NULL)   // 到底就返回true 
        return true;
    
    if (Position == 0 && root->val >= target)
        return false;
    if (Position == 1 && root->val <= target)
        return false;
    return DFS(root->left, target, Position) && DFS(root->right, target, Position);
    // 注意这里的Position是不变的，root->left和root->right 相对于根（值为target的结点）都在一颗子树上
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL)
        return true;
    
    return DFS(root->left, root->val, 0) && DFS(root->right, root->val, 1) && 
            isValidBST(root->left) && isValidBST(root->right);
}
*/
/*
思路二：
中序遍历
我们有一个很正常的思路就是，通过中序遍历来保存这个二叉树的值，可以发现如果为中序遍历保存这些值的话，他们为单调递增排列，那么判断是否为二叉搜索树只需要比较相邻结点即可，从这个思路我们可以得到：
*/
void inOrder(struct TreeNode* root,int arr[],int *len){
    if(root != NULL){
        inOrder(root->left,arr,len);
        arr[(*len)++]=root->val;
        
        inOrder(root->right,arr,len);
    }
}
bool isValidBST(struct TreeNode* root){
    int arr[10000];
    int len=0;
    inOrder(root,arr,&len);
    for(int i=0;i<len-1;i++){
        if(arr[i]>=arr[i+1]){
            return false;
        }
    }
    return true;
}
