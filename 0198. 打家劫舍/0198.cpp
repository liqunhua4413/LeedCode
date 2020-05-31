/*
思路：动态规划
1.房屋就一个：最高金额就是此房屋的钱。
2.房屋两个：最高金额就是两个房屋中比较多的一个。
3.前K个房屋：最高金额max{第k个房屋的钱+前k-2个房屋最高的钱， 前k-1个房屋最高的钱}。
dp状态转移方程：dp[i]=max(dp[i−2]+nums[i],dp[i−1])
*/
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        if(len == 0) return 0;       
        if(len >= 1) dp[0] = nums[0]; //房屋就一个：最高金额就是此房屋的钱。
        if(len >= 2) dp[1] = max(nums[0], nums[1]); //房屋两个：最高金额就是两个房屋中比较多的一个。

        for(int i = 2; i < len; i++){ 
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[len-1];
    }
};
*/
/*
思路2：动态规划+滚动数组
思路1使用了数组存储结果。考虑到每间房屋的最高总金额只和该房屋的前两间房屋的最高总金额相关，因此可以使用滚动数组，在每个时刻只需要存储前两间房屋的最高总金额。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        if(len == 0) return 0;       
        if(len == 1) return nums[0]; //房屋就一个：最高金额就是此房屋的钱。
        int first = nums[0], second = max(nums[0], nums[1]); //房屋两个：最高金额就是两个房屋中比较多的一个。

        for(int i = 2; i < len; i++){ 
            int temp = second;
            second = max(nums[i]+first, second);
            first = temp;
        }
        return second;
    }
};
