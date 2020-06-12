/*
思路：排序+双指针
排序：方便去掉重复解。
双指针：可以把两层for循环降低到到一层for循环。
这里有个细节：双指针的for循环里
for(int left = i + 1; left < len; left++){
    判断并更新right; //这里需要先改变right。
    判断满足条件不满足; //这里再对想要的结果进行处理。
}
这样才能很好的实现双指针的思想：left有值，right也有值不满足条件后，循环一圈回来，再left++，然后判断并更新right.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 3) return res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; i++){
            if(nums[i] > 0) break; //如果第一个元素大于0，则和一定大于0，结束循环。
            if(i > 0 && nums[i] == nums[i-1]) continue; //跳过连续的重复数。
            int right = len - 1;
            for(int left = i + 1; left < len; left++){
                if(left > i + 1 && nums[left] == nums[left-1]) continue;  //去重。
                //此时nums[right]不用去重，因为nums[left]已经去重，当找到满足条件的结果后，下一个nums[left]一定不同,如果此时还想满足条件，则nums[right]也一定不是原先的值了。
                while(left < right && nums[i] + nums[left] + nums[right] > 0) //结果大于0，右指针左移。
                    right--; 
                if(left >= right) break; //左指针大于等于右指针时，结束循环。
                if(nums[i] + nums[left] + nums[right] == 0)  //满足条件，加到结果中。
                    res.push_back({nums[i], nums[left], nums[right]});                 
            }
        }
        return res;
    }
};
