/*
思路：前缀和+哈希表
1.利用前缀和把题目意思转化：
    元素之和能被 K 整除的子数组数目 就是 有几种 i、j 组合，使得 第 i ~ j 项的和 mod K == 0
        等价于
    有几种 i、j组合，满足(preSum[j]−preSum[i−1])modK==0
        等价于
    有几种 i、j 组合，满足pre[j]modK==pre[i−1]modK
2.利用哈希表保存前缀和整除K的结果：
    key：前缀和 mod K 。数值作为 key
    value：这个结果值出现了几次
    每次用一个变量 preSum ，保存求出的前缀和 mod K，存入哈希表。
3.步骤：
    预置边界情况:
        preSum = 0
        遍历数组 A 之前，map 提前放入 0:1，代表【前缀和 mod K 等于 0】已经出现 1 次
    遍历数组 A 的每一项，求当前项的前缀和,看 map 中是否已存在 key == 当前前缀和mod K：
        如果存在，表明之前求出的前缀和里面有，它 mod K == 当前前缀和 mod K
        把之前求出的前缀和 mod K 出现的次数，累加给 count
    把当前项的前缀和mod K ，存入 map 中：
        之前没有存过，则作为 key 存入，值为 1
        之前存过，则对应值 +1
4.注意：
    前缀和同样是map的下标，不能是负数，负数需要做一些转换。
    举例：K = 4，求得一个前缀和为 -1 ， -1 % K = -1 ，3 % K = 3
    看似模的结果不相等，一个为 -1 一个为 3 ，但它们应该记到一组
    因为它们前缀和之差：3 - (-1) 为 4 。 4 % K = 0
    所以 mod K 的结果 -1 ，要加上 K ，转成正数的 3

*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int preSum = 0, res = 0;
        unordered_map<int,int> um{{0,1}};
        int len = A.size();
        for(int i = 0; i < len; i++){
            preSum += A[i];
            int modulus = preSum % K;
            if(modulus < 0) modulus += K;  //负数前缀和做转换
            if(um.find(modulus) != um.end()) res += um[modulus];
            um[modulus]++;
        }
        return res;
    }
};
