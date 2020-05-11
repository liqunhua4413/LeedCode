/*
思路：快速幂
比如a^b,按照一般想法就是把a连乘b次，这样一来时间复杂度是O(n)级，快速幂能做到O(logn)。
首先把b写成它的二进制形式，设该二进制数第i位的权值为2^(i-1)，i * 2^(i-1)是每一次要做的乘方次数
那么假设b=11，11的二进制是1011，11 = 2³×1 + 2²×0 + 2¹×1 + 2º×1=2³+2¹+2º，所以：a¹¹= a^2º* a ^2¹ * a^2³
代码中n&1是取末位，只有当前位为1时才要乘； n/=2是将n右移一位，取新的位做末位；x*=x就是X^(2^i)，是下一次要乘的因子
*/
double quickMul(double x, long long N) {
    double ans = 1.0;
    // 贡献的初始值为 x
    double x_contribute = x;
    // 在对 N 进行二进制拆分的同时计算答案
    while (N > 0) {
        if (N % 2 == 1) {
            // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
            ans *= x_contribute;
        }
        // 将贡献不断地平方。其实就二进制的1、2、4、8......
        x_contribute *= x_contribute;
        // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
        N /= 2;
    }
    return ans;
}

double myPow(double x, int n){
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

/*
思路：二分法
有时间再补吧。
*/

/*
double myPow(double x, int n){
}
*/
