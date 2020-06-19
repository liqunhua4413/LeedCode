class Solution {
public:
    bool isPalindrome(string s) {       
        int len = s.size();
        if(len <= 1) return true;
        string ss;
        for(int i = 0; i < len; i++){
            if( ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))
                ss.push_back(tolower(s[i]));
        }
        string temp = ss;
        reverse(temp.begin(), temp.end());
        return temp == ss;
    }
};
