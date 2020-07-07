/*
思路描述：这道题动态规划的思路应该蛮清晰的，可以使用 dp[i][j] 来表示 从起点到达 [i,j] 有多少条路径，
    由于机器人只能向下或者向右移动，所以 dp[i][j] 只可能由 dp[i - 1][j] 和 dp[i][j - 1] 移动过来，所以
如果 obstacleGrid[i][j] == 1，dp[i][j] = 0，因为没有路
如果 obstacleGrid[i][j] == 0，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化第一行第一列
        for(int i = 0; i < m; i ++){
            if(obstacleGrid[i][0] == 1) break;
            else dp[i][0] = 1;
        }
        for(int j = 0; j < n; j ++){
            if(obstacleGrid[0][j] == 1) break;
            else dp[0][j] = 1;
        }
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                } else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};
