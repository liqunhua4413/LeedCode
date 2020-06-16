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
 思路1：队列
    作者：henryheliang
*/
 class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;
        //利用队列和循环，实现广度优先遍历
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p!=NULL)
            {
                res += to_string(p->val); // int to string
                res+=",";  // string 类型的用法。直接 + 
                q.push(p->left);
                q.push(p->right);
            }
            else
            {
                res +="null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto vals = split(data); //好吧，我不会切割序列化后的字符
        queue<TreeNode*> q;
        if(vals[0]=="null") return NULL;
        q.push(new TreeNode(stoi(vals[0])));
        TreeNode *res = q.front();
        for(int i=1;i<vals.size();)
        {
            if(vals[i]!="null")
            {
                auto p = new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->left = p;
            }
            ++i;
            if(vals[i]!="null")
            {
                auto p = new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->right = p;
            }
            ++i;
            q.pop();
        }

        return res;
    }

    //切割字符串，反序列化的关键
    vector<string> split(string &data)
    {
        int start = 0;
        vector<string> res;
        while(1)
        {
            auto end = data.find(',', start);
            if(end == string::npos) break;
            res.push_back(data.substr(start,end-start));
            start=end+1;
        }
        return move(res);
    }

};

/*
思路2：递归
    作者：fuag-a
按照先序遍历逐个向res中添加节点值信息，注意加个空格作为分界线；
利用streamstirng和>>运算符自动消除空格特点，
每次迭代开始，仅需进行一次>>运算即可取得节点信息，按照先序遍历的顺序建立二叉树即可。
*/
/*
class Codec {
public:
    void pre(TreeNode* root,string& s){
        if(root==NULL) {
            s+="NULL  ";
            return;
        }
        s+=to_string(root->val);
        s+="  ";
        pre(root->left, s);
        pre(root->right, s);
    }
    TreeNode* construct(stringstream & in){
        string s;
        in>>s;
        if(s=="NULL") return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = construct(in);
        root->right = construct(in);
        return root;  
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        pre(root, res);
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream in(data);
        return construct(in);
    }
};
*/

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
