// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
    private:
      queue<int> q1;
      queue<int> q2;
    
    public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp;
        int temp2;
        if (q1.size() == 1) {
            q1.pop();
            return q1.front();
        }
        while (q1.size() != 1) {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        q1.pop();
        while (q2.size() != 0) {
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        int temp;
        int temp2;
        while (q1.size() != 1) {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        temp2 = q1.front();
        while (q2.size() != 0) {
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        return temp2;
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */