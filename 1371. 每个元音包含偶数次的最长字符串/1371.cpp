/*
思路一：暴力法
超出时间限制
*/
/*
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int len = s.size();
        int flagA = 0;
        int flagE = 0;
        int flagI = 0;
        int flagO = 0;
        int flagU = 0;
        int res = 0;
        int max = 0;

        for(int i = 0; i < len; i++){
            flagA = flagE = flagI = flagO = flagU = 0;
            max = 0;
            for(int j = i; j < len; j++){
                if(s[j] == 'a') flagA++;
                if(s[j] == 'e') flagE++;
                if(s[j] == 'i') flagI++;
                if(s[j] == 'o') flagO++;
                if(s[j] == 'u') flagU++;
                max++;
                if( (max > res) && (flagA%2 == 0) && (flagE%2 == 0) && (flagI%2 == 0) && (flagO%2 == 0) && (flagU%2 == 0) ) res = max;
            }
        }
		return res;
    }
};
*/

/*
思路：
官方思路优化暴力法：
	（1）枚举所有子串时间复杂度O(n^2):前缀和优化成O(n)。
	    1.前缀和：在不重复遍历子串的前提下，求出子串中5个元音字母出现的次数。
		对于任意子串[left,right]，其中每个元音字母出现的次数：pre[right][k] - pre[left-1][k]，其中k表示不同的元音字母。
	（2）每个子串里5个元音字母出现次数的统计：优化成统计其奇偶性。
	    1.状态压缩：优化成统计其奇偶性
	    如果子串[left,right]满足条件，即元音字母只出现偶数，则pre[right][k]和pre[left][k]奇偶性一定相同，所以再次优化，把求元音字母出现次数变为求元音字母出现的奇偶性，因为只有5个元音字母，所以状态压缩到2^5=32种，用哈希表就可以实现。
	    2.位操作：哈希表的优化
        将这么一个结构当作我们哈希表存储的键值，如果题目稍作修改扩大了字符集，那么维护起来可能会比较吃力。考虑到出现次数的奇偶性其实无非就两个值，0代表出现了偶数次，1代表出现了奇数次，可以用位操作来实现，即[0,31]=[(00000),(11111)]。
	    具体实现：建立一个32位的数组，每个下标表示一种状态，下标对应的值表示这种状态出现的位置。初始时首元素为0，其它位置为-1，表示初始状态（status为0），即所有元音字母都没有的情况。然后开始遍历数组，判断元素是否是元音字母，更新状态值。如果是元音字母，则判断此次的状态以前是否出现过，如果没有出现则把该状态对应的位置更新一下，如果出现过，则判断这次出现的位置和上次出现的位置的长度是否大于结果ans值，更新结果ans值。
	（3）求结果
	快速找到满足条件的最长子符串，其实要做的就是如何快速找到最小的j∈[0,i)，满足pre[left][k]和pre[right][k]奇偶性相同，那么字符串s[left+1,right]长度就是right-left。遍遍历遍更新即可。
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, status = 0, n = s.length();
        vector<int> pos(1 << 5, -1); //pos数组初值为32个-1，代替哈希表。
        pos[0] = 0; //首元素为0表示初始状态即所有元音字母为0的情况。
        
        for (int i = 0; i < n; ++i) {
            switch(s[i]){
                case 'a': status ^= 1<<0; break;
                case 'e': status ^= 1<<1; break;
                case 'i': status ^= 1<<2; break;
                case 'o': status ^= 1<<3; break;
                case 'u': status ^= 1<<4; break;
                default: break;
            }
            if (pos[status] != -1)  //如果此状态出现过，判断子串长度，看是否需要更新结果ans。
				ans = max(ans, i + 1 - pos[status]);
            else  //如果没有出现，则把此状态的值记录到对应的数组中。
				pos[status] = i + 1;
        }

        return ans;
    }
};





