/*
思路：
定义dp[i][j] 为A 以i结尾，B以j结尾的最长公共子数组。那么可以分为两类：

    如果A[i] == B[j], 那么有dp[i][j] = 1 + d[i-1][j-1]
    A[i] 不等于 b[j], 则dp[i][j] = 0

计算的过程中维护一个最大值即可。
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (A[i] == B[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                    ans = max(ans, dp[i + 1][j + 1]);
                }
            }
        }
        return ans;
    }
};
