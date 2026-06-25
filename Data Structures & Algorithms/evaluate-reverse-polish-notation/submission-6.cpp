class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
          if(it=="+"){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first+second);
          }
          else if(it=="*"){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first*second);
          }
          else if(it=="-"){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second- first );
          }
          else if(it=="/"){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second/first );
          }
          else{
            st.push(stoi(it));
          }
        }
        return st.top();
    }
};
