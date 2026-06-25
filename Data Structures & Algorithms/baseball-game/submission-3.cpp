class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto it:operations){
            if(it=="+"){
                int second=st.top();
                st.pop();
                int first=st.top();
                st.push(second);
                st.push(second+first);
            }
            else if(it=="D"){
                st.push(st.top()*2);
            }
            else if(it=="C"){
                st.pop();
            }
            else{
                st.push(stoi(it));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};