/*
思路：
从头开始，遍历数组，更新能跳的最远距离。
当遍历到的位置已经大于能跳到的最远距离，循环结束，返回false。
*/
bool canJump(int* nums, int numsSize){
    int max = 1; //能跳的最远距离，数组起始下标为0的位置，max为1表示第1个位置。  
    for(int i = 0; i < numsSize; i++){
        if(i + 1 > max){  //遍历到的位置已经大于能跳到的最远距离。
            return false;
        }
        max = (i + 1 + nums[i])  > max ? (i + 1 + nums[i]) : max;
        if(max >= numsSize) return true; //当跳的最远距离大于数组长度时，结束。
    }
    return true;
}
