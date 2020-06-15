
/*
思路：想不出来的思路，参考作者：yizhe-shi
思路描述：首先题意就是把大于 value 的值缩小到 value，使得总和最接近 target。
最简单的做法就是先对整个数组排一下序，然后再求和 sum，如果 sum <= target，value 返回最大值就好了，因为没必要再缩小某些值了。
如果 sum > target，我们可以遍历一遍 arr，然后分别取 value 为数组中的值直到发现取第 i 个值 sum >= target，并且 i 左边的元素和为 sumLeft，那么如果 i 及 i 右边的数字全变成
ans = (target - sumLeft)/(n - i)，这时候总和就是 sumLeft + ans*(n - i) = target
但是因为 ans = (target - sumLeft)/(n - i) 是向下取整，所以要比较一下分别取 ans 和 ans+1哪个更接近 target。
比如：
1 2 3 target = 3，右边两个变成 (3 - 1)/2 = 1 最好
注意：上面思路证明在下面，作者：java_Lee
    1.记arr的前缀和数组:pre[i]=arr[0]+arr[1]+...+arr[i-1]。
    2.则 S(arr[i]) = pre[i] + arr[i]*(N-i) 即前i项和 + 剩下的都是arr[i]
    3.不难发现 S(a)是关于a的单调非减函数
    sum[i+1] + (n-i-1) * (arr[i+1]) - sum[i] - (n-i) * (arr[i]) = (sum[i+1] - sum[i]) + (n-i-1) * (arr[i+1]) - (n-i) * (arr[i]) = (n-i) * arr[i+1] - (n-i) * arr[i] >= 0
    4.第2步只要找到最小的i，使得 S(arr[i])>=target，则答案ans必然介于(arr[i-1]+1)到arr[i]之间。这是利用S(a)和arr[i]的单调性。
*/
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());//排序
        int sum = accumulate(arr.begin(), arr.end(), 0);//求和
        int n = arr.size();
        if(sum <= target) return arr.back(); //如果 sum <= target，value 返回最大值就好
        if(arr[0] * n >= target){  //如果选择最小的元素乘以n > target，直接选择target/n或者target/n+1即可。
            int ans = target/n;
            if(target - ans * n < (ans + 1) * n - target)
                return ans;
            else
                return ans + 1;
        }
        int sumLeft = arr[0];
        for(int i = 1; i < n; i ++){
            int sum = sumLeft + arr[i] * (n - i);  //单调非减函数S(a)。
            if(sum >= target){
                int ans = (target - sumLeft)/(n - i);
                if(target - sumLeft - ans*(n - i) <= (ans + 1) * (n - i) + sumLeft - target)
                    return ans;
                else
                    return ans + 1;
                break;
            }
            sumLeft += arr[i];
        }
        return 0;
    }
};



