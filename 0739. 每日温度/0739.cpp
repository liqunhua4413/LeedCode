/*
思路：单调栈
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> res(len,0);
        stack<int> s;
        s.push(0); //第一个元素下标入栈
        for(int i = 1; i < len;i++){
            //栈不空，数组元素大于栈顶元素，则找到需要的结果，栈顶出栈。
            while(!s.empty() && T[i] > T[s.top()]){
                res[s.top()] = i - s.top(); //所求结果为元素下标之差。
                s.pop(); //栈顶出栈。
            }
            s.push(i); //新元素入栈。
        }
        return res;
    }
};
