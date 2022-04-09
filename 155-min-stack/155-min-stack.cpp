class MinStack {
public:
    stack<int> s, minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty() || s.empty()){
            s.push(val);
            minStack.push(val);
            return;
        }
        s.push(val);
        if(minStack.top()>val){ 
            minStack.push(val);
        } else{
            minStack.push(minStack.top());
        }
        
    }
    
    void pop() {
        if(minStack.empty() || s.empty()){
            return;
        }
        else{
            minStack.pop();   
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */