/*
思路1：动态规划
（1）我们可以用 f(i) 表示以第 i 位结尾的前缀串翻译的方案数，考虑第 i 位单独翻译和与前一位连接起来再翻译对 f(i) 的贡献。
（2）单独翻译对 f(i) 的贡献为 f(i - 1)；
（3）如果第 i - 1位存在，并且第 i - 1位和第 i 位形成的数字 x 满足 10≤x≤25，那么就可以把第 i - 1 位和第 i 位连起来一起翻译，对 f(i) 的贡献为 f(i - 2)，否则为 0。
（4）我们可以列出这样的动态规划转移方程：
        f(i)=f(i−1)+f(i−2)[i−1≥0,10≤x≤25]
（5）边界条件是 f(-1) =0，f(0) = 1。方程中 [c] 的意思是 c 为真的时候 [c]=1，否则 [c]=0。
*/
/*
class Solution {
public:
    int translateNum(int num) {
        string numS = to_string(num);
        int len = numS.size();
        //赋初值，dp[0]赋值为1。
        vector<int> dp(len,1);
        //若第0位和第1位形成的数字 x 满足 10≤x≤25，则dp[1]赋值为2，否则还是初值1。
        if( 10 <= stoi(numS.substr(0,2)) && stoi(numS.substr(0,2)) <= 25) dp[1] = 2;
        for(int i = 2; i < len; i++){
            int flag = 0;
            if(10 <= stoi(numS.substr(i-1,2)) && stoi(numS.substr(i-1,2)) <= 25) flag = 1;
            dp[i] = dp[i-1] + dp[i-2] * flag;
        }
        return dp[len-1];
    }
};
*/
/*
思路2：动态规划+滚动数组
优化一下其他代码。
*/
class Solution {
public:
    int translateNum(int num) {
        string numS = to_string(num);
        int len = numS.size();
        //赋初值，dp[i-1]和dp[i-2]赋初值为1。
        int first  = 1, second = 1;
        //若第0位和第1位形成的数字 x 满足 10≤x≤25，则dp[1]赋值为2，否则还是初值1。
        if( "10" <= numS.substr(0,2) && numS.substr(0,2) <= "25") second = 2;
        for(int i = 2; i < len; i++){
            int flag = 0;
            int temp = first;
            first = second;
            if("10" <= numS.substr(i-1,2) && numS.substr(i-1,2) <= "25") flag = 1;
            second = second + temp * flag;
        }
        return second;
    }
};







