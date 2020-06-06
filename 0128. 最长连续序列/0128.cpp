/*
思路1：先排序，后比较，时间复杂度 O(nlog(n))。
*/
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int res = 1;
        int tempMax = 1;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len - 1; i++){
            if(nums[i] == nums[i+1]) continue; //当碰到重复的数，跳过。
            if(nums[i] + 1 == nums[i+1]) tempMax++;
            else tempMax = 1;
            res = max(tempMax, res);
        }
        return res;
    }
};
*/
/*
思路2：利用set，时间复杂度 O(n)。
（1）Set 查找元素的时间复杂度是 O(1)，Set 又能给数组去掉重复元素
（2）将数组元素存入 set 中，遍历数组 nums
（3）如果 nums[i] - 1 存在于 set ，说明 nums[i] 不是连续序列的起点，跳过，继续遍历
（4）当前项没有“左邻居”，它就是连续序列的起点
（5）不断在 set 中查看 cur + 1 是否存在，存在，则 count +1
（6）cur 不再有 “右邻居” 了，就算出了一段连续序列的长度
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int res = 1;
        int count = 1;
        unordered_set<int> si;
        for(int n : nums) si.insert(n);

        for(int i = 0; i < len; i++){
            if(si.find(nums[i] - 1) != si.end()) continue; //当前项有左邻居，不是连续序列的起点，跳过。
            count = 1;
            int cur = nums[i];
            while(si.find(cur + 1) != si.end()){ //当前项没有“左邻居”，它就是连续序列的起点，不断看有没有右邻居，更新count。
                count++; 
                cur++;
            }     
            res = max(count, res);
        }
        return res;
    }
};









