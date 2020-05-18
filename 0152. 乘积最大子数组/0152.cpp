
/*
思路：暴力法
两层for循环。
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0; //结果
        int len = nums.size();
        int isAllMinus = 1; //判断是否全是负数。

        for(int i = 0; i < len; i++){
            int maxPro = 1; //最大乘积初值为1
            if(nums[i] > 0) isAllMinus = 0; //只要有大于0的数，标志位更新为0.
            for(int j = i; j < len; j++){
                maxPro *= nums[j];
                if(maxPro > res) res = maxPro;
            }
        }

        if(isAllMinus && res == 0){ //如果全是负数,且res为0，找到数组中最大的一个数返回即可。
            res = nums[0];
            for(int i = 1; i < len; i++){
                if(nums[i] > res) res = nums[i];
            }
        }

        return res;
    }
};
