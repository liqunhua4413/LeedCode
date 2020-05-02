
/*
思路：
最笨方法：找到所有子串，比较不重复的子串长度，得到最长子串。
*/
bool isInString(char * s, int len){ //判断新出现的字符是否在以前的子串里。
    for(int i = 0; i < len; i ++){
        if(s[i] == s[len]) return false;
    }
    return true;
}
int lengthOfLongestSubstring(char * s){
    int len = 0;
    if(!s || strlen(s) == 0) return  0; //处理空指针和空字符串的问题。
    for(int i = 0; s[i] != '\0'; i++){ //求出字符串总长度len。
        len = i + 1;
    }

    int tempLen = 1,resLen = 1;
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){ //两个for循环得到所有子串。
            if(isInString(&s[i], j - i)) tempLen = j - i + 1;
            else break;
            if(tempLen > resLen) resLen = tempLen;
            tempLen = 1;
        }    
    }

    return resLen;
}
