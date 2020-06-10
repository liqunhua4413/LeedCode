/*
思路1：数字转字符串
*/
/*
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }
};
*/
/*
思路2：求得位数，首尾数字依次比较。
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int left = 0, right = 0;
        int div = 1;
        while(x / div >= 10){
            div *= 10;
        }
        while(x > 0){
            left = x / div;
            right = x % 10;
            if(left != right) return false;
            x = (x - left * div) / 10;
            div /= 100;
        }
        return true;
    }
};
