
/*
思路一；
最笨方法：找到所有子数组，得到最大和。不过这种方法超出时间限制。
*/
/*
int arraySum(int* nums, int len){ //求子数组的和。
    int res = 0;
    for(int i = 0; i < len; i++){
        res += nums[i];
    }
    return res;
}

int maxSubArray(int* nums, int numsSize){
    if(!nums) return 0;
    int maxSum = nums[0];
    int tempSum = nums[0];

    for(int i = 0; i < numsSize; i++){
        for(int j = i; j < numsSize; j++){ //两次for循环得到所有子数组。
                if( ( tempSum = arraySum(&nums[i], j - i + 1) ) > maxSum) maxSum = tempSum;             
        }
    }
    return maxSum;
}
*/


/*
思路二；
优化最笨方法：三层for循环，优化到两层。
还有一种特殊情况，数组全是负数，这个需要加标志位isAllMinus单独判断。
*/
int maxSubArray(int* nums, int numsSize){
    if(!nums) return 0;
    int maxSum = nums[0];
    int tempSum = 0;
    int isAllMinus = 1; //判断是否全是负数。

    for(int i = 0; i < numsSize; i++){
        tempSum = 0;
        if(nums[i] > 0) isAllMinus = 0; //只要有大于0的数，标志位更新为0.
        for(int j = i; j < numsSize; j++){ //两次for循环得到所有子数组。
                tempSum += nums[j];
                if(tempSum > maxSum) maxSum = tempSum;             
        }
    }
    
    if(isAllMinus){ //如果全是负数，找到数组中最大的一个负数返回即可。
        maxSum = nums[0];
        for(int i = 1; i < numsSize; i++){
            if(nums[i] > maxSum) maxSum = nums[i];
        }
    }
    return maxSum;
}


/*
思路三：贪心策略
从头开始，只要子数组和小于0，就抛弃前面的数组，接着从下一个开始。
若子数组和大于0，则继续往后加，当大于maxSum时，更新maxSum。
还有一种特殊情况，数组全是负数，这个需要加标志位isAllMinus单独判断。
*/
/*
int maxSubArray(int* nums, int numsSize){
    if(!nums) return 0; //数组如果是空指针，这里只能返回0，不能返回空指针，是题的Bug。
    int maxSum = nums[0];
    int tempSum = 0;
    int isAllMinus = 1; //判断是否全是负数。
    
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0) isAllMinus = 0; //只要有大于0的数，标志位更新为0.
        if(nums[i] > maxSum) maxSum = nums[i]; //单个元素也可能是最大和的连续子数组。
        tempSum += nums[i];
        if(tempSum < 0) tempSum = 0; //如果前面的子数组和小于0，则抛弃。
        if(tempSum > maxSum) maxSum = tempSum; //如果前面子数组和大于最大和，则更新最大和。  
    }

    if(isAllMinus){ //如果全是负数，找到数组中最大的一个负数返回即可。
        maxSum = nums[0];
        for(int i = 1; i < numsSize; i++){
            if(nums[i] > maxSum) maxSum = nums[i];
        }
    }
    return maxSum;
}
*/

