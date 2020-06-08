/*
思路：并查集
第一次遍历 "x==y" 公式，调用 union 方法将它们两两放入同一个集合中
第二次遍历 "x!=y" 公式，通过 findRoot 方法查验两者是否真的不在一类
如果是一类，出现矛盾，返回false
如果查验一路通过，返回true
*/
class UnionFind
{
  private:
    vector<int> parent;
    vector<int> rank; // 秩

  public:
    UnionFind(int max_size) : parent(vector<int>(max_size)), rank(vector<int>(max_size, 0)){
        for (int i = 0; i < max_size; ++i){
            parent[i] = i;
        }               
    }
    int find(int x){
         //find时路径压缩：将路径上的所有节点都直接连接到根节点上。
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
    void to_union(int x1, int x2){
        int f1 = find(x1);
        int f2 = find(x2);
        //按秩合并:谁所在的树的高度更大，它所在的树的根节点就作为新树的根节点
        if (rank[f1] > rank[f2])
            parent[f2] = f1;
        else
        {
            parent[f1] = f2;
            //如果r1与r2相等，两棵树任意合并，并令新树的秩为r1 + 1。
            if (rank[f1] == rank[f2])
                ++rank[f2];
        }
    }
    bool is_same(int e1, int e2){
        return find(e1) == find(e2);
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int len = equations.size();
        if(len <= 0) return true;
        UnionFind uf(26); //初始化26个小写字母的父节点都是自己。

        //第一次遍历，合并 == 的字母。
        for(auto e : equations){
            if(e[1] == '=') uf.to_union(e[0] - 'a', e[3] - 'a');
        }

        //第二次遍历，处理 != 的公式
        for(auto e : equations){
            if(e[1] == '!' && uf.is_same(e[0] - 'a', e[3] - 'a')) return false;
        }

        return true;
    }
};
