class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k == 0) return res; //k为0返回空。
        if(shorter == longer) return vector<int>(1, k * shorter); //长短相等，返回唯一的结果。
        for(int i = 0; i <= k; i++){ //遍历k+1种情况。
            res.push_back(shorter * (k - i) + longer * i);
        }
        return res;
    }
};
