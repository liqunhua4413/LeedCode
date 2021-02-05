class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len % 2 == 1) return false;

        stack<char> sc;
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sc.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                switch(s[i]){
                    case ')':
                    {
                        s[i] = '(';
                        break;
                    }
                    case ']':
                    {
                        s[i] = '[';
                        break;
                    }
                    case '}':
                    {
                        s[i] = '{';
                        break;
                    }
                    default:
                        break;
                }
                if(!sc.empty() && sc.top() == s[i]){
                    sc.pop();
                }
                else{
                    return false;
                }
            }
            else return false;
        }
        if(sc.empty()) 
            return true;
        else 
            return false;
    }
};
