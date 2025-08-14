class MinStack {
public:
    stack<int> st;
    multiset<int> ms;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        ms.insert(val);
    }
    
    void pop() {
        auto it = ms.find(st.top()); 
        ms.erase(it); 
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it=ms.begin();
        return *it;
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