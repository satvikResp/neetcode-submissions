class MinStack {
public:
    stack<int>st;
    stack<int>minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty()) {
        minstack.push(val);
    }
    else {
        minstack.push(min(minstack.top(), val));
    }

    }
    
    void pop() {
      if(!minstack.empty()){
        minstack.pop();
      }
      if(!st.empty()){
        st.pop();
      }


    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
