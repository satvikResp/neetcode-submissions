class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<string>st;
        int sum=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=="+"){  
                int topv=stoi(st.top());
                st.pop();
                topv+=stoi(st.top());
                st.push(to_string(topv-stoi(st.top())));
                st.push(to_string(topv));
            }
            else if(s[i]=="C"){ 
               st.pop();
            }
            else if(s[i]=="D"){
                int topv=stoi(st.top());
                st.push(to_string(2*topv));
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
        sum+=stoi(st.top());
        st.pop();
        }
        return sum;
    }
};