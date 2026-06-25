class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string>st;
        for(auto it:operations){
            if(it=="+"){
                string second=st.top();
                st.pop();
                string first=st.top();
                st.push(second);
                int cal=stoi(second)+stoi(first);
                st.push(to_string(cal));
            }
            else if(it=="D"){
                string second=st.top();
                int cal=stoi(second)*2;
                st.push(to_string(cal));
            }
            else if(it=="C"){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }
        return ans;
    }
};