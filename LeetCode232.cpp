class MyQueue {
public:
 /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!nums_b.empty()) {
            nums_a.push(nums_b.top());
            nums_b.pop();
        }
        nums_a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!nums_a.empty()) {
            nums_b.push(nums_a.top());
            nums_a.pop();
        }
        int num = nums_b.top();
        nums_b.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        while (!nums_a.empty()) {
            nums_b.push(nums_a.top());
            nums_a.pop();
        }
        return nums_b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums_a.empty() && nums_b.empty();
    }
private:
    stack <int> nums_a;
    stack <int> nums_b;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
