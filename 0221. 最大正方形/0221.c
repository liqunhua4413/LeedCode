/*
思路：暴力法
从左上角开始遍历，如果为0，不处理。
如果为1，再判断其它几个数是不是1.
*/
//c语言没有标准的最大、最小函数，可以如下宏定义。
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
#define min(a,b) ( ((a)>(b)) ? (b):(a) )

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0 || *matrixColSize == 0) return 0;
    int maxSide = 0; //最大正方形的边.
    int rows = matrixSize, cols = *matrixColSize;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == '1'){ //遇到正方形左上角为1的情况。
                maxSide = max(maxSide, 1);

                int currentMaxSide = min(rows - i, cols - j); //计算当前这个正方形最大的可能长度。
                for(int k = 1; k < currentMaxSide; k++){ //判断在这个可能长度内，实际最大的长。
                    int flag = 1; //标志位：正方形每扩大一个长度，看是否数字都是1.
                    if(matrix[i+k][j+k] == '0') break;  //先判断对角线上的数字是0，直接跳出循环。
                    for(int m = 0; m < k; m++){ //判断除了对角线，其他数字是什么。
                        if( (matrix[i+k][j+m] == '0') || (matrix[i+m][j+k] == '0') ){ //其它数字如果有0，跳出循环。
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) maxSide = max(maxSide, k+1); //标志位为真，则可能的最大长度就是真的。
                    else break;
                }
            }
        }
    }
    int maxSquare = maxSide * maxSide;
    return maxSquare;
}
