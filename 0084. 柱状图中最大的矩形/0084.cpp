/*
思路1：暴力法
超出时间限制
*/
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        int width = 0, height = 0, mid = 0;

        for(int i = 0; i < len; i++){
            width = 1, height = heights[i], mid = i;
            while(--mid >= 0 && heights[mid] >= height) width++; //直到左边界小于高度，宽度一直增加。
            mid = i;
            while(++mid < len && heights[mid] >= height) width++; //直到右边界小于高度，宽度一直增加。
            res = max(res, width * height); //更新最大面积。
        }        
        return res;
    }
};
*/
/*
思路2：单调栈
（1）栈中存储的为数组下标。
（2）枚举所有柱形的上边界，作为整个矩形的上边界。
（3）然后求出左右边界：
1.找出左边离它最近的，比它小的柱形
2.找出右边离它最近的，比它小的柱形
*/
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> left2right(len),right2left(len);

        stack<int> sta;
        //从左向右构造单调栈
        for(int i = 0; i<len; i++)
        {
            while(sta.size() && heights[sta.top()] >= heights[i])//栈不空，栈顶若大于上边界，弹出
                sta.pop();
            if(!sta.size())//栈若为空，说明左边一直到边界都没有最小的，令其值为 -1. 最小为0
                left2right[i] = -1;
            else
                left2right[i] = sta.top();//栈不为空，说明左边找到边界最小，即栈顶
            sta.push(i);//压入当前值
        }

        sta = stack<int>();
        //从右向左构造单调栈
        for(int i = len-1; i>=0; i--)
        {
            while(sta.size() && heights[sta.top()] >= heights[i])//栈不空，栈顶若大于上边界，弹出
                sta.pop();
            if(!sta.size())//栈若为空，说明右边一直到边界都没有最小的，令其值为n，最大为n
                right2left[i] = len;
            else
                right2left[i] = sta.top();//栈不为空，说明右边找到边界最小，即栈顶
            sta.push(i);
        }

        int ans = 0;
        for(int i = 0; i<len; i++)
        {
            ans = max(ans,(right2left[i] - left2right[i] - 1)*heights[i]);//n - (-1) -1 最大长度为n
        }

        return ans;
    }
};
*/
/*
思路3：
（1）遇到比栈顶元素大的值，则直接入栈；
否则，此时的元素为右边界，可以先记为heights[target]，开始弹出栈顶元素，直到heights[target]比栈顶元素大。
注意：每次弹出的栈顶元素都是我们要的目标矩形
（2）每次弹出一个元素时，此时的栈顶元素便是该目标矩形的左边界，即目标矩形左边第一个比它高度小的矩形；
右边界我们之前已经知道了，这样子目标矩形的最大面积便为heights[top_index] * (right - left - 1)，遍历时保存最大值，最后返回即可。
（3）注意：
可以在heights数组最后插入一个0，来代表末尾边界。防止单调递增while循环进不去的特殊情况。
注意在求左边界时，目标矩形无左边界的情况，此时赋值为-1。
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        
        if(heights.size() == 0)
            return 0;

        int maxArea = heights[0];

        heights.push_back(0);   //设置末尾边界

        for(int i = 0; i < heights.size(); i++){

            while(!st.empty() && heights[i] < heights[st.top()]){

                int top_index = st.top();

                //右边第一个比heights[st.top()]小的元素
                int right = i;

                st.pop();
                //左边第一个比heights[st.top()]小的元素
                int left = st.empty() ? -1 : st.top();	//注意无左边界的情况

                maxArea = max(maxArea, heights[top_index] * (right - left - 1));
            }

            st.push(i);
        }

        return maxArea;
        
    }
};

