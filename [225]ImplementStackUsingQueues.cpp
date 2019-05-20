#include <iostream>
#include <deque>

using namespace std;

class MyStack {
    deque<int> queue;
    int top_ptr;
    
public:
    /** Initialize your data structure here. */
    MyStack() : top_ptr( -1 ) {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue.push_back( x );
        top_ptr++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (top_ptr < 0) return -1;
        if (top_ptr == 0) {
            int val = queue.front();
            queue.pop_front();
            top_ptr--;
            return val;
        }

        std::deque<int> aux;
        for (int i = 0; i <= top_ptr - 1; ++i) {
            aux.push_back( queue.front() );
            queue.pop_front();
        }
        int val = queue.front();
        queue = aux;
        top_ptr--;
        return val;
    }
    
    /** Get the top element. */
    int top() {
        if (top_ptr < 0) return -1;
        return queue[top_ptr];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */