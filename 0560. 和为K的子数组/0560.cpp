/*
思路一：暴力法
把每个子数组的和求出来。
不过要稍微优化一下，只用两层for循环，循环里面直接把和记录一下。
*/
/*
//下面这种方法居然超出时间限制。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int res = 0;
        vector<int>::iterator ii;
        vector<int>::iterator ij;
        for(ii = nums.begin(); ii != nums.end(); ii++){
            int sum = 0;
            for(ij = ii; ij != nums.end(); ij++){
                sum += *ij;
                if(sum == k) res++;
            }
        }
        return res;
    }
};
*/
/*
//把上面访问数组方式的迭代器换成成下标，就通过了。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int res = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int sum = 0;
            for(int j = i; j < len; j++){
                sum += nums[j];
                if(sum == k) res++;
            }
        }
        return res;
    }
};
*/
/*
思路二：前缀和
    跟脑筋急转弯一样，需要缕清，现在的目的就是要看看子数组和为K的个数。
    比如：i到j这段子数组和为k，nums[i] + nums[i+1] + ...+nums[j-1] + nums[j] = k;
    上面也可以转变为：sum(j) - sum(i-1) = k;
    然后再变一下，sum(i-1) = sum(j) - k;
    这样和为k的子数组，一开始不知道从哪开始找i，这回变成了直接从头开始一直求和到i-1的位置即可，这里i-1也可以写成i。
    因此我们可以遍历一遍数组，记录下前j项的和sum,用Map的键存储sum，Map的值存储sum出现的次数。
    假设当前扫到第j位，记录它的前j项和sum，用该和减去k，即sum-k，判断sum-k是否为某个位置的前i项和。
    若是，则取出map键为sum(i)的map值，累加更新一下。
    最后还要把这次的和sum更新到mp里面。
注意：
    初值mp[0] = 1;  
    这个就是考虑特殊情况，因为数组的长度为 [1, 20,000]，这里考虑如果数组只有一个元素的情况，或者有子数组和为0的情况。
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  //这个就是考虑特殊情况，因为数组的长度为 [1, 20,000]，这里考虑如果数组只有一个元素的情况。
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++; //这里看起来简单，实际容易理解不全，实际这一行代码等于下面注释里面的代码。
            /*
            //首先判断mp里面有没有sum这个值，没有就mp[sum]置为1，有才mp[sum]++。
            if(mp.find(sum) == mp.end())  mp[sum] = 1;  
            else mp[sum]++;
            */
        }
        return count;
    }
};
