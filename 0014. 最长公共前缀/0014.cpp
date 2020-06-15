class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string res = "";
        if(len == 0) return res;
        int count = strs[0].size();
        for(int i = 0; i < count; i++){  //以第一个字符串为例，挨个字母循环该字符串
            int c = strs[0][i];
            for(int j = 0; j < len; j++){  //循环比较所有字符串的字母是否相同
                if(i == strs[j].size() || strs[j][i] != c) //如果后面的字符串已到达最大长度，或者不是公共前缀，结束循环
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
