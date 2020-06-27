/*
思路：
（1）把num[i]放在i-1处：即下标0处存的1、下标1处存的2、...下标n-1处存的n。即数组[1, 2, 3, ..., n-1,n]。
    如何把num[i]放在i-1处？遍历数组，处理遍历到的每一个位置。
    比如遍历第一个位置即下标为0的地方：只要nums[0]不为1，且在1~n-1之间，nums[0]不等nums[nums[0]-1]则交换。
（2）放完后，遍历i处nums[i]不为i+1的即为结果,返回i+1。
（3）如果0~n-1放的都是对应的1~n，则返回n+1即可。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int len = nums.size();
       if(len == 0) return 1;
       for(int i = 0; i < len; i++){ //遍历每个位置
            while(nums[i] > 0 && nums[i] < len && nums[i] != nums[nums[i]-1]) //每个位置从当前位置，一直循环交换，直到不满足条件。
                swap(nums[i], nums[nums[i]-1]);
       } 
       for(int i = 0; i < len; i++){
           if(nums[i] != i + 1) return i+1;
       }
       return len+1;
    }
};
