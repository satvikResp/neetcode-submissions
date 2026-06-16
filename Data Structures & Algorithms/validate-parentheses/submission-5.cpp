class Solution {
public:
    bool isValid(string s) {
        if(s.size()<=1){
            return false;
        }
        stack<char>st;
        for(const char& it:s){
            if((it=='(')||(it=='{')||(it=='[')){
                st.push(it);
            }
            else{
                if(it=='}'){
                    if(st.empty()|| st.top()!='{'){
                    return false;
                    }
                }
                else if(it==')'){
                    if(st.empty() || st.top()!='('){
                    return false;
                    }
                     
                }
                 else if(it==']' ){
                    if(st.empty() || st.top()!='['){
                    return false;
                    }
                }

                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        else
        return false;
    }
};
