class MyStack {
public:
queue<int>q2;
    MyStack() { 
        
    }
    
    void push(int x) {
        queue<int>tempq;
        if(q2.empty()){
            q2.push(x);
        }
        else{
            tempq.push(x);
            while(!q2.empty()){
                tempq.push(q2.front());
                q2.pop();
            }
            q2=tempq;
        }
    }
    
    int pop() {
        int val=q2.front();
        q2.pop();
        return val;
    }
    
    int top() {
       return q2.front();
    }
    
    bool empty() {
        if(q2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */