/*
思路：动态规划
动态规划：
1.定义：dp[i]表示s的前i个字符能否拆分成一个或多个wordDict字典中的单词 所以需要定义dp的长度为s.size() + 1
2.dp[0] = true 表示空字串是可以拆分成字典中的单词 即：前0个字符是可以拆分成字典中的单词
3.状态转移方程: dp[i] = dp[j] && s[j, i - 1] dp[j]表示s[0, j - 1]和s[j, i - 1]是否同时在字典中
4.eg:s = "leetcode", wordDict = ["leet", "code"]
dp[8] = dp[4] + check("code") (1)dp[4] = true 表示s[0, 3] = "leet"是字典中的单词 (2) check("code") 即s[4,7] 表示检查"code"是不是字典中的单词

作者：OrangeMan
链接：https://leetcode-cn.com/problems/word-break/solution/cdong-tai-gui-hua-by-orangeman/
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        vector <bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
