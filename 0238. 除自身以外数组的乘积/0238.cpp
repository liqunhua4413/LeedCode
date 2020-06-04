/*
思路：作者：orange-32
厉害：时间复杂度不仅 O(n) ，空间复杂度为 O(1)，题中说输出数组不被视为额外空间。 
简单易懂
eg [1,2,3,4]:
1.初始化 res = [1,1,1,1], left = 1, right = 1;
2.i = 0, j = 3 res = [1,1,1,1], left = 1, right = 4;
3.i = 1, j = 2 res = [1,1,4,1], left = 2, right = 12;
4.i = 2, j = 1 res = [1,12,8,1], left = 6, right = 24;
5.i = 3, j = 0 res = [24,12,8,6] 不重要了，输出res
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int left = 1, right = 1;
        vector<int> res(len,1);
        //数组乘积等于左边数组乘积乘以右边数组乘积。
        for(int i = 0, j = len - 1; i < len; i++, j--){ //一次循环其实相当于两次循环：一次是不断更新左数组left值，让结果数组不同位置的值乘以对应的左数组值；另一次就是右边了。
            res[i] *= left, res[j] *= right; //先让数组
            left *= nums[i], right *= nums[j];           
        }
        return res;
    }
};
