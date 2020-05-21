/*
思路：暴力法
超出时间限制
*/
/*
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string res;
        int max = 0;
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                string temp(s.begin()+i, s.begin()+j+1); //temp是原子字符串，这里里必须j+1。
                string temp1 = temp; //原子字符串
                reverse(temp.begin(), temp.end()); //temp已经反转了。
                if( (temp1 == temp) && (temp.size() > max) ){
                    res = temp1;
                    max = temp.size();
                }
            }
        }
        return res;
    }
};
*/
/*
思路：动态规划
官方思路：
    我们用P(i,j)表示s[i:j]是否为回文串，如果P(i,j)=true，则s[i:j]是回文串。（s[i:j]就是字符串s的第i到j个字母组成的串）
   动态规划思路： 对于一个子串而言，如果它是回文串，并且长度大于2，那么将它首尾的两个字母去除之后，它仍然是个回文串。例如对于字符串“ababa”，如果我们已经知道“bab” 是回文串，那么“ababa” 一定是回文串，这是因为它的首尾两个字母都是“a”。
    状态转移方程：P(i,j)=P(i+1,j-1)^(Si == Sj)。也就是说，只有s[i+1:j−1]是回文串，并且s的第i和j个字母相同时，s[i:j] 才会是回文串。
    状态初始值：上面的讨论都是基于子串长度大于2的前提下，下面考虑确定状态的初始值，即子串的长度为1或2。对于长度为1的子串，它显然是个回文串；对于长度为2的子串，只要它的两个字母相同，它就是一个回文串。因此我们就可以写出动态规划的边界条件：
        P(i,i)=true
        P(i,i+1)=(Si == Si+1)
    根据这个思路，我们就可以完成动态规划了，最终的答案即为所有P(i,j)=true中j−i+1（即子串长度）的最大值。
    注意：在状态转移方程中，我们是从长度较短的字符串向长度较长的字符串进行转移的，因此一定要注意动态规划的循环顺序。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n)); //定义一个n维n列的二维数组。
        string ans;
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                if (len == 0) { //动归初始值，所有长度为1的字符串P(i,j)赋值为true。
                    dp[i][j] = 1;
                }
                else if (len == 1) { //动归初始值，给所有长度为2的字符串P(i,i+1)赋值。
                    dp[i][j] = (s[i] == s[j]);
                }
                else { //动归状态转移方程
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && len + 1 > ans.size()) { //如果P(i,j)为true，且j−i+1的长度大于结果字符串的长度。
                    ans = s.substr(i, len + 1); //更新结果值。
                }
            }
        }
        return ans;
    }
};

