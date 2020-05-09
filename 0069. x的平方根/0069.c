
/*
思路：二分查找
找到一个数的平方小于x，但加1的平方大于x，则改数是x的平方根。
*/
int mySqrt(int x){
    int  res = 0;
    int left = 0, right = x;
    if(x == 1) return res = 1; //特殊情况。
    while(left <= right){
            long long mid = (left + right) / 2; //因为题库的数比较大，所以mid定义成long long类型。
            if( (mid * mid <= x) && ( (mid+1)*(mid+1) > x) ) return res = mid;  //这里的<=的=不能少。
            else if(mid * mid > x) right = mid - 1;
            else if(mid * mid < x) left = mid + 1;
    }
    return res;
}
