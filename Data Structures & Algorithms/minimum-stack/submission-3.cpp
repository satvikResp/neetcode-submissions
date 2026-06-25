class MinStack {
public:
    stack<int>st;
    stack<int>minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!minstack.empty()){
            if(minstack.top()<val){
                minstack.push(minstack.top());
            }
            else minstack.push(val);
        }
        else minstack.push(val);
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
