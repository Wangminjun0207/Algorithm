/****************************************
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
******************************************/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack_.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = stack_.back();
        stack_.pop_back();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return stack_.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack_.empty();
    }
    vector<int> stack_;
};