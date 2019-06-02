/**********************************
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
***********************************/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        queue_.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = queue_.front();
        queue_.pop_front();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return queue_.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue_.empty();
    }
    deque<int> queue_;
};