class MinStack {
public:
    stack<int>st;
    int minimum=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        minimum=min(minimum,val);
        st.push(val);
    }
    
    void pop() {
        if(st.top()==minimum){
            st.pop();
            stack<int>temps;
            temps=st;
            int new_min=INT_MAX;
            while(!temps.empty()){
                new_min=min(new_min,temps.top());
                temps.pop();
            }
            minimum=new_min;
        }
        else{
        st.pop();
        }
    }
    
    int top() {
       return st.top();
       
    }
    
    int getMin() {
        return minimum;
    }
};
