class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        int flag = 0; //进位
        int maxLen = lenA;
        int sum = 0;
        string res;
        //1. a和b如果长度不等，先前面补0，补齐
        if(lenA > lenB){
            b = string(lenA - lenB, '0') + b;
        } 
        else if(lenB > lenA){
            a = string(lenB - lenA, '0') + a;
            maxLen = lenB;
        } 
        //遍历每位相加
        for(int i = maxLen - 1; i >=0; i--){
            sum = a[i] - '0' + b[i] - '0' + flag;
            if(sum >= 2) flag = 1;
            else flag = 0;
            res.push_back((sum % 2) + '0');
        }
        //判断最高位用不用进1
        if(flag) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
