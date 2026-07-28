class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        stack<int>st;
        for(auto it:asteroids){
            bool destroyed=false;
            if(it>0){
                st.push(it);
                continue;
            }
            else{
                if(st.empty()){
                    st.push(it);
                    continue;
                }
                while(!st.empty() && st.top()>0 && it<0 && st.top()<abs(it)){
                    st.pop();
                }
                if(!st.empty() && st.top()>abs(it)){
                    continue;
                }
                if(!st.empty() && st.top()==abs(it)){
                    st.pop();
                    continue;
                }
                st.push(it);
                
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};