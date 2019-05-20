/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (33.67%)
 * Total Accepted:    230.9K
 * Total Submissions: 685.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */

#include <iostream>

class MinStack {
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int x) : val( x ), prev( nullptr ), next( nullptr ) {}
    };

    int min_val;
    int top_ptr;
    Node* stack;

public:
    /** initialize your data structure here. */
    MinStack() : min_val( INT_MAX ), top_ptr( -1 ) {
    
    }
    
    void push(int x) {
        if (top_ptr < 0) {
            stack = new Node( x );
        }
        else {
            stack->next = new Node( x );
            stack->next->prev = stack;
            stack = stack->next;
        }
        top_ptr++;
        if (min_val > x) min_val = x;
    }
    
    void pop() {
        if (top_ptr >= 0) {
           if (min_val == stack->val) {
                Node* node = stack->prev;
                int new_min = INT_MAX;
                while (node != nullptr) {
                    if (node->val < new_min) {
                        new_min = node->val;
                    }
                    node = node->prev;
                }
                min_val = new_min;
            }
        
            if (top_ptr == 0) {
                delete stack;
            }
            else {
                stack = stack->prev;
                delete stack->next;
            }
            top_ptr--;
        }
    }
    
    int top() {
        return stack->val;
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */