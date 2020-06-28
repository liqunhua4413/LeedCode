/*
思路：双指针
（1）左右指针left、right初始指向数组首元素。
（2）右指针右移，直到区间和大于等于s。
（3）更新结果值，左指针右移，直到结果小于s。
（4）循环直到数组末尾。
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int sum = 0, left = 0;
        int res = INT_MAX;

        for(int right = 0; right < len; right++){
            sum += nums[right];
            while(sum >= s){
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
