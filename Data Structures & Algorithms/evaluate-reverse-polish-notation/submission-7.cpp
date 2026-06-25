class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(it=="+"||it=="-"||it=="/"||it=="*"){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            
          if(it=="+"){
            
            st.push(first+second);
          }
          else if(it=="*"){
           
            st.push(first*second);
          }
          else if(it=="-"){
            
            st.push(second- first );
          }
          else if(it=="/"){
           
            st.push(second/first );
          }
         
            }
         else{
            st.push(stoi(it));
          }
        }
        return st.top();
    }
};
