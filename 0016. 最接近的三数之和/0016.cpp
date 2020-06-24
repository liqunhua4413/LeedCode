/*
思路：枚举+双指针
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0, temp = INT_MAX;

        for(int i = 0; i < len - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; //去重
            int left = i + 1, right = len - 1;
            while (left < right) {
                if(left > i + 1 && nums[left] == nums[left-1]){ //去重
                    left++;
                    continue; 
                }  
                if(right < len - 1 && nums[right] == nums[right+1]){ //去重
                    right--;
                    continue;  
                } 
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return target;  // 如果和相等直接返回          
                if (abs(sum - target) < temp){ //如果绝对值更小，则更新结果
                    temp = abs(sum - target);
                    res = sum;
                }
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return res;
    }
};
