/* 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则
并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。循环队列的一个好处是我
们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下
一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：
MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。

示例：
MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4 */

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        head = -1;   // 初始化队头指针
        trail = -1;  // 初始化队尾指针
        count = k+1; // 记录队列容量（但是能入队的元素比队列容量少1，为了区分队满和队空）
        queue = new int[k+1];  // 给队列分配空间
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        this->trail = (this->trail+1)%this->count; // 队尾指针后移
        this->queue[this->trail] = value;  // 元素在队尾入队
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        this->head = (this->head+1)%this->count; // 队头元素出队
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        return this->queue[this->head+1]; // 队不空时获取队头元素
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        return this->queue[this->trail];  // 队不空时获取队尾元素
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(this->trail==this->head)
        {
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((this->trail+1)%this->count==(this->head+count)%count)
        {
            return true;
        }
        return false;
    }
private:
    int head;     // 队头指针(应该使用front)
    int trail;    // 队尾指针
    int count;    // 队列容量
    int *queue;   // 队列指针
};
