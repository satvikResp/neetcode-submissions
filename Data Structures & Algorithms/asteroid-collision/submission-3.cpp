class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        bool des=false;
        for(auto it:asteroids){
            while(!st.empty() && st.top()>0 && it<0){
                if(st.top()<abs(it)){
                    st.pop();
                }
                else if(st.top()==abs(it)){
                    st.pop();
                    des=true;
                    break;
                }
                else{
                    des=true;
                    break;
                }
            }
            if(des==false){
                st.push(it);
            }
             
            des=false;
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};