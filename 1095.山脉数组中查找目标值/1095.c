/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

/*
思路：
三次二分查找：
找山峰
找山峰左边区间
找山峰右边区间
*/

/*
//方法一：递归实现

int searchLowToHigh(MountainArray* nums, int low, int high, int val)
{
	if (low <= high)
	{
		int mid = (low + high) / 2, num = get(nums, mid);
		if (num == val)
			return mid;
		if (num < val)
			return searchLowToHigh(nums, mid + 1, high, val);
		if (num > val)
			return searchLowToHigh(nums, low, mid - 1, val);
	}
	return -1;
}

int searchHighToLow(MountainArray* nums, int low, int high, int val)
{
	if (low <= high)
	{
		int mid = (low + high) / 2, num = get(nums, mid);
		if (num == val)
			return mid;
		if (num < val)
			return searchHighToLow(nums, low, mid - 1, val);
		if (num > val)
			return searchHighToLow(nums, mid + 1, high, val);
	}
	return -1;
}

int searchMax(MountainArray* nums, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2, num0 = get(nums, mid - 1), num1 = get(nums, mid), num2 = get(nums, mid + 1);
		if (num0<num1&&num1>num2)
			return mid;
		if (num1 < num2)
			return searchMax(nums, mid + 1, high);
		if (num1 > num2)
			return searchMax(nums, low, mid);
	}
	return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
	int maxIndex = searchMax(mountainArr, 0, length(mountainArr) - 1);
	int result = searchLowToHigh(mountainArr, 0, maxIndex, target);
	return result == -1 ? searchHighToLow(mountainArr, maxIndex, length(mountainArr) - 1, target) : result;
}
*/

//方法二：循环实现
int searchPeak(MountainArray* nums, int numSize)
{
    int low, high, mid;
    int num0, num1, num2;
    low = 0;
    high = numSize - 1;
    while(low <= high){
        mid = (low + high) / 2;
        num0 = get(nums, mid-1); //这里需要先调用get函数得到数组值，防止下面过度调用此函数。
        num1 = get(nums, mid);
        num2 = get(nums, mid+1);
        if( (num0 < num1) && (num1 > num2) ){
            return mid;  //当中间值比前后两个数都大时，此值就是峰值，返回其下标。
        }
        if(num1 > num2){
            high = mid;
        }
        if(num1 < num2){
            low = mid + 1;
        }
    }
    return -1;
}

int searchLowToPeak(MountainArray* mountainArr, int peakIndex, int target)
{
    int low, high, mid;
    int num;
    low = 0;
    high = peakIndex;
    while(low <= high){
        mid = (low + high) / 2;
        num = get(mountainArr, mid);
        if(target == num){
            return mid;
        }
        if(target > num){
            low = mid + 1;
        }
        if(target < num){
            high = mid - 1;
        }
    }
    return -1;
}

int searchPeakToHigh(MountainArray* mountainArr, int peakIndex, int target)
{
    int low, high, mid;
    int num;
    low = peakIndex;
    high = length(mountainArr) - 1;
    while(low <= high){
        mid = (low + high) / 2;
        num = get(mountainArr, mid);
        if(target == num){
            return mid;
        }
        if(target > num){
            high = mid -1;
        }
        if(target < num){
            low = mid + 1;
        }
    }
    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int numSize = length(mountainArr);
    int peakIndex = searchPeak(mountainArr, numSize); //峰值下标
    int result;
    if( (result = searchLowToPeak(mountainArr, peakIndex, target)) != -1){
        return result;
    }
    else return searchPeakToHigh(mountainArr, peakIndex, target);
}
