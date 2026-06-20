class MinStack {
public:
stack<int>mainstack;
stack<int>minstack;

    MinStack() {
        
    }
    
   void push(int val) {
    mainstack.push(val);

    if(minstack.empty()){
        minstack.push(val);
    }
    else{
        minstack.push(min(val, minstack.top()));
    }
}
    
    void pop() {
        if(!mainstack.empty()){
        mainstack.pop();
        minstack.pop();
        }
    }
    
    int top() {

        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
