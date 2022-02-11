// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
    
     private:
        int size;
        stack<int> s1;
        stack<int> s2;
        int item;
    public:
    /** Initialize your data structure here. */
  
        MyQueue() {
        
        }
    
    /** Push element x to the back of queue. */
        void push(int x) {
            int temp;
            if (s1.empty()) {
                s1.push(x);
            } else {
             while (s1.size() != 0) {
                temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
            s1.push(x);
            while (s2.size() != 0) {
                temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        item = s1.top();
        s1.pop();
        return item;
    }
    
    /** Get the front element. */
    int peek() {
        item = s1.top();
        return item;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (s1.empty()) {
            return true;
        } else {
            return false;
        }
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */