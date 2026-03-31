class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push(val);
        if (minimumStack.empty() || val <= minimumStack.top()) {
            minimumStack.push(val);
        }
    }
    
    void pop() {
        if (minStack.top() == minimumStack.top()) {
            minimumStack.pop();
        }
        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return minimumStack.top();
    }

private:
    stack<int> minStack;
    stack<int> minimumStack;
};
