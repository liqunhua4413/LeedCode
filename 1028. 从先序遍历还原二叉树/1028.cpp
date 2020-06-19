/*
思路：双栈方法：单调栈+辅助栈
（1）单调栈里存的是下标，主要标志树节点的深度
（2）辅助栈里存的是树节点，初始值为根节点，实现指向其左右子节点。
*/
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
		stack<TreeNode*> st; //存储树节点。栈顶保持的是下一个节点的父节点。
		TreeNode* root = new TreeNode(num(S));
		st.push(root); //根节点入栈.

        stack<int> si; //单调栈：单调非减
        si.push(0); //根节点的深度入栈

        while(!S.empty()){
            int dCur = depth(S); //求出下一个节点的深度
			//如果下一个节点是子节点，则直接指向，并st入栈。
            if(dCur > si.top()){ 
				auto temp = new TreeNode(num(S));
				st.top()->left = temp;
				st.push(temp);
                si.push(dCur);
                continue;
            }
			//如果下一个节点和上一个节点是同级节点，则左子节点st.top出栈，此时栈顶指向右子节点temp。
			//右子节点入栈，这里保证左右子节点有一个在栈顶即可，而且保证si和st出栈入栈顺序一样。
            if(dCur == si.top()){ 
				auto temp = new TreeNode(num(S));
				st.pop();
				si.pop();
				st.top()->right = temp; //栈顶左右子节点都找到，也可以出栈了。
				st.push(temp);
				si.push(dCur);
            	continue;
            }
			//如果下一个节点比上一个节点深度要小，则si出栈。
			//找到父节点之后，父节点的右子节点即是该节点，把此右子节点入栈。
            if(dCur < si.top()){
				while(si.top() >= dCur){
					si.pop();
					st.pop();
				}
				auto temp = new TreeNode(num(S));
				st.top()->right = temp;
				st.push(temp);
				si.push(dCur);
				continue;
            }
        }
        return root;
    } 
private:
    //下面两个函数处理字符串s后，会改变s：即会把字符串最前面的字符依次删掉
    int num(string& s){ //得到字符串s最前面的一个数。
        int res = 0;
        while(!s.empty() && s[0] != '-'){
            res = res * 10 + (s[0] - '0');
            s.erase(0,1);
        }
        return res;
    }
    int depth(string& s){ //得到字符串s最前面的‘-’数，即深度。
        int res = 0;
        while(!s.empty() && s[0] == '-'){
            res++;
            s.erase(0,1);
        }
        return res;
    }
};
