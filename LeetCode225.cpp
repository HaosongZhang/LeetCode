class MyStack {
public:
MyStack() {

}

/** Push element x onto stack. */
void push(int x) {

    m_queue.push(x); //入队

    //将之前的元素出队并插入队尾
    for (int i = 0; i < m_queue.size() - 1; ++i)
    {
        m_queue.push(m_queue.front());
        m_queue.pop();
    }
}

/** Removes the element on top of the stack and returns that element. */
int pop() {
    int front = m_queue.front();
    m_queue.pop();
    return front;
}

/** Get the top element. */
int top() {
    return m_queue.front();
}

/** Returns whether the stack is empty. */
bool empty() {
    return m_queue.empty();
}
private:
std::queue<int> m_queue;


};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
