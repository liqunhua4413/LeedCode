/*
思路：
前后双指针。
相同，双指针移动，不同则删除一个前字符或者后字符，继续移动观察结果。
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int low = 0, high = s.size()  - 1;
        while(low < high){
            if(s[low] == s[high]){
                low++;
                high--;
            }
            else return checkPalindrom(s, low + 1, high) || checkPalindrom(s, low, high - 1);
        }
        return true;
    }
private:
    bool checkPalindrom(string& s, int low, int high){
        while(low < high){
            if(s[low] == s[high]){
                low++;
                high--;
            }
            else return false;
        }
        return true;
    }
};
