class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='('||it=='['||it=='{'){
                st.push(it);
            }
            else{
                if(st.empty()){
                    return false;
                }

                if(it==')'){
                    if(!st.empty() && st.top()!='('){
                        return false;
                    }
                    st.pop();
                }
                else if(it==']'){
                     if(!st.empty() && st.top()!='['){
                        return false;
                    }
                    st.pop();
                }
                else if(it=='}'){
                     if(!st.empty() && st.top()!='{'){
                        return false;
                    }
                    st.pop();
                }
                
            }
        }
        if(!st.empty()){
            return false;
        }
        else
        return true;

    }
};
