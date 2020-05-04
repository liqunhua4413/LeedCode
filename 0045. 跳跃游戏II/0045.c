/*
思路：
从头开始，遍历数组。
每一步，都更新能跳到的最远距离。也更新步数。
如果最远距离大于数组长度，则输出最小步数。
否则在这一步的起始位置到最远距离之间找一个能跳最远距离的数，作为下一步跳跃的点。
依次遍历数组。
比如：[2,3,1,1,4]
第一步：遍历数组第一个元素2.
第二步：在2这个距离内，有3和1，则选择3.即从2跳到3.更新步数。
第三步：这样从3这个元素，依次遍历数组，直到跳跃的位置大于数组长度。输出最小步数。
*/
int jump(int* nums, int numsSize){
    int minNum = 0; //最小步数。
    int max = 0; //最远距离。
    int next = 0; //下一次跳跃的位置。
    if(!nums) return 0;
    if(numsSize <= 1) return 0;

    for(int i = 0; i < numsSize; i = next){ //每次更新跳跃的位置next
        minNum++; //每跳一次，最小步数加1.
        next = i + 1; //默认下一次跳跃的位置next，为这次跳跃点的下一个位置。下面循环更新next。
        max = nums[i] + i; //默认跳跃最远距离max,是这次跳跃点跳到的最远距离。下面循环更新max。
        if(max >= numsSize - 1) return minNum; //跳跃的最远距离当到达数组最后位置时，结束返回最小步数。
        for(int j = i, k = 1; k < nums[i] + 1; k++){ //在这次跳跃的位置，到这个位置能跳到的最远距离之间，找一个next。
            if(nums[j + k] + j + k > max){ //下一个跳跃位置next，就是这段能跳跃的位置中，下一次能跳到最远距离的位置。
                next = j + k;
                max = nums[j + k] + j + k;
            }
        }
    }
    return minNum;
}
