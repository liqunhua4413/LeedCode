/*
思路：
（1）[i,j]的分数：A[i] + A[j] + i - j = A[i] + i + A[j] - j
（2）从前往后，先遍历依次求出A[i] + i，记为mx；
（3）当求到j时，就让 A[j] - j和mx的值最大即可。
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int len = A.size();
        if(len <= 1) return 0;
        int res = 0;
        int mx = A[0] + 0; //A[j] - j的值
        for(int j = 1; j < len; j++){            
            res = max(res, A[j] - j + mx);
            mx = max(mx, A[j] + j);
        }
        return res;
    }
};
