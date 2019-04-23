/* 设计实现双端队列。
你的实现需要支持以下操作：
MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。

示例：
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4 */


class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        front = 0;   // 初始化队头指针
        trail = 0;  // 初始化队尾指针
        count = k+1; // 记录队列容量（但是能入队的元素比队列容量少1，为了区分队满和队空）
        queue = new int[k+1];  // 给队列分配空间
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }
        queue[front] = value;
        front = (front-1+count)%count;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
        {
            return false;
        }
        trail = (trail+1)%count;
        queue[trail] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        front = (front+1)%count; // 队头元素出队
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        trail = (trail-1+count)%count; // 队头元素出队
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
        {
            return -1;
        }
        return queue[(front+1)%count]; // 队不空时获取队头元素
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
        {
            return -1;
        }
        return queue[trail];  // 队不空时获取队尾元素
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(trail==front)
        {
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if((trail+1)%count==(front)%count)
        {
            return true;
        }
        return false;
    }
private:
    int front;    // 队头指针
    int trail;    // 队尾指针
    int count;    // 队列容量
    int *queue;   // 队列指针
};