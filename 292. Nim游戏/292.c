/*
思路：
1.作为先手，只需把超过4整数倍的石头拿出来先。
2.然后对手每次拿多少，你拿的数只需和他加起来为4就行。
3.这样最后你拿走最后几个，他就没有啦。
*/
bool canWinNim(int n){
    return (n % 4 != 0);
}
