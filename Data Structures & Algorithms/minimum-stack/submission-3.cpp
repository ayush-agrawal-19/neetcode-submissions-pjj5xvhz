class MinStack {
public:

    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push(val);
        int min;

        if (!extraStack.empty()) {
            min = extraStack.top();
            if (val <= min) {
                extraStack.push(val);
            }
            else {
                extraStack.pop();
                extraStack.push(val);
                extraStack.push(min);
            }
        }
        else {
            extraStack.push(val);
        }
    }
    
    void pop() {
        if (minStack,top() == extraStack.top()) {
            extraStack.pop();
        }
        else {
            int min = extraStack.top();
            extraStack.pop();
            extraStack.pop();
            extraStack.push(min);
        }

        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return extraStack.top();
    }

private:
    stack<int> minStack;
    stack<int> extraStack;
};
