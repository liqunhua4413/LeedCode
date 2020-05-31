class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int len = candies.size();
        int maxNum = 0;
        bool temp = true;
        if(len == 0) return res;
        for(int i = 0; i < len; i++){
            maxNum = max(maxNum, candies[i]);
        }
        for(int i = 0; i < len; i++){
            (candies[i] + extraCandies < maxNum) ? (temp = false) : (temp = true);
            res.push_back(temp);
        }
        return res;
    }
};
