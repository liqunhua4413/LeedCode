/*
思路：动态规划
（1）状态d[i][j]：表示字符规律p前j个字符 能否匹配 字符串s前i个字符。
（2）初值全赋为false，然后一些边界值为true的，单独赋值。
    a.状态初始值：d[0][0] = true，表示两个都为空时，也是匹配的。
    b.首列d[i][0] = false，就不用再赋值了。
    c.首行d[0][i] = true，是有条件的，p是偶数，且偶数位都是'*'，才满足
（3）状态转移方程
    情况1：p[j] == 字母
        且p[j] == s[i]时，dp[i][j] = dp[i-1][j-1]
    情况2：p[j] == '.'
        这时p[j]一定能匹配s[i],故 dp[i][j] = dp[i-1][j-1]
    情况3：p[j] == '*'，*本身不能单独表示字符，只能和之前的字符结合，那么需要考虑p[j-1]
        p[j-1] != s[i]，此时不管p[j-1]有多少个都不能和s[i]匹配，只有为0个才有可能匹配，0表示*a被消除了，那么dp[i][j] = dp[i][j-2]
        p[j-1] == s[i]，此时由于p[j-1]可以表示1到无穷大个p[j-1]，那么逐个判断s[i]往前有多少个相同的p[j-1]，直到找到第一个不相同的为止，
        期间dp[i][j] = dp[i][j] || dp[i-k][j-k]，k表示从s[i]往前找，有多少个相同的p[j-1]
    不过这种情况3比较复杂，还得枚举，换成下面的思路：
参考：https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/
最后来个归纳：
    1.如果 p[j] == s[i] : dp[i][j] = dp[i-1][j-1]；
    2. 如果 p[j] == '.' : dp[i][j] = dp[i-1][j-1]；
    3.如果 p[j] == '*'：
        3.1如果 p[j-1] != s[i] : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
        3.2如果 p[j-1] == s[i] or p[j-1] == '.'：
            dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
            or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
            or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
 注意：题目太操蛋，难理解
   （1） s="abc"，p=".*"的结果为true？因为'*' 表示前面的字符可以出现0次或无数次，所以 p=".*" 可以看作成 p="..." ，而 '.' 是万能字符，因此可以匹配成 "abc" ，所以应该为true的。
   （2）s = "aab"，p = "c*a*b"结果为true？因为这里虽然有'c'，不过这里 'c' 看成了 0 个，因为'c'在'*'前面，可以表示0个。
   （3）s = ""，p = "c*a*b*a*a*a*"结果为true？因为偶数位为'*'，直接把前面的那个字符给消去了，表示匹配前面零个字符。
   （4）如果连续有两个*，又该怎么处理？事先把字符串连续的多个 '*' 消成一个。
*/
class Solution {
public:
    bool isMatch(string s,string pp){
        //假设pp串中存在连续多个*，把它们变成一个*
        string p;
        for (int i = 0; i < pp.size(); ++i) {
            if (i == 0 || pp[i] != '*' || (pp[i] == '*' && pp[i-1] != '*')) {
                p.push_back(pp[i]);
            }
        }

        //赋初值
        int m = s.length(), n = p.length();
	    bool dp[m+1][n+1];  
        memset(dp,false,(m+1)*(n+1)); //初始全为false，下面边界为true的，单独赋值。
	    dp[0][0]=true;  //初始值：两者都为空，也是匹配的，为true。
        //初始化首行：字符串s长度为0，字符规律p长度不为0时，值是不确定的。
        //"" 和p的匹配，只有a*a*a*a*a*这种偶数为'*'能够消去前面字母的字符串P才能匹配空串，其他的是都是false。
        for (int i = 1; i <= p.length(); i+= 2) {
            if (p[i] == '*' && dp[0][i-1]) {
                dp[0][i+1] = true;
            }
        }

        //开始dp
	    for(int i=0;i<m;i++){
		    for(int j=0;j<n;j++){
			    if(p[j] == s[i] || p[j]=='.'){
				    dp[i+1][j+1]=dp[i][j];
			    }
                else if(p[j]=='*'){
				    if(p[j-1]!=s[i] && p[j-1]!='.'){
					    dp[i+1][j+1]=dp[i+1][j-1];
				    }
                    else{
					    if(dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]) {
						    dp[i+1][j+1]=true;
					    }
				    }
			    }
		    }
	    }
	    return dp[m][n];
    }
};
