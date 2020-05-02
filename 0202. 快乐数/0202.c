/*
思路：
1.快慢指针判断有没有循环；
2.当循环结束的时候判断最后结束时快慢指针的数是否为1.
*/
int calcSquare(int n){
    int result = 0;
    while(n > 0){
        result += (n%10) * (n%10);
        n /= 10;
    }
    return result;
}

bool isHappy(int n){
    int slow = calcSquare(n);
    int fast = calcSquare(slow);
    while(fast != slow){
        slow = calcSquare(slow);
        fast = calcSquare(fast);
        fast = calcSquare(fast);
    }
    return slow == 1;

}
