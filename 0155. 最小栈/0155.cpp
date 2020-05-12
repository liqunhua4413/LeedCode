
/*
思路：一个栈实现
1.用c写还需要创建动态可扩展的栈，不如用C++写。
2.方法一可以创建辅助栈，每入栈一个元素，辅助栈压入一个最小元素。
3.方法二就一个栈，每次入栈的同时压入一个最小元素，出栈也同样操作。
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int min = x; //如果minStack一开始为空，或者minStack的栈顶最小元素大于x，给min赋值为x。
        if(!minStack.empty() && minStack.top() < x) min = minStack.top(); //minStack的栈顶最小元素小于x，给min赋值为minStack.top()。
        minStack.push(x); //首先把该元素压入栈。
        minStack.push(min); //把最小元素入栈。
    }
    
    void pop() {
        minStack.pop(); //出栈最小元素；
        minStack.pop(); //出栈压入的元素。
    }
    
    int top() { //这里需要得到栈顶元素，而我们栈顶元素是最小元素，所以需要先把最小元素出栈。
        int temp = minStack.top(); //保存栈顶最小元素。
        minStack.pop(); //出栈最小元素。
        int res = minStack.top(); //这时栈顶元素才是真正需要的栈顶元素。
        minStack.push(temp); //这里还需要把最小元素入栈。
        return res;
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
