
/*
思路：
方法一：建立一个哈希map，遍历数组，得到每个数组的出现的次数。
方法二：直接所有数异或，相同的全部变为0，只剩不同的那个数。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); it++){ //异或数组的所有元素。
            res ^= *it;
        }
        return res;
    }
};
